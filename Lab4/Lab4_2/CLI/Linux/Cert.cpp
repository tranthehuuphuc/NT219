#include "openssl/bio.h"
#include "openssl/x509.h"
#include "openssl/pem.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "openssl/err.h"

using namespace std;

#ifdef _WIN32
#ifdef BUILD_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif
#else
#define DLL_EXPORT __attribute__((visibility("default")))
#endif

extern "C"
{
    DLL_EXPORT int verifyAndSaveCert(const char *format, const char *rootCACertFile, const char *intermediateCertFile, const char *websiteCertFile, const char *outputFile);
}

// Function to verify a certificate
bool verifyCertificate(X509 *cert, STACK_OF(X509) * intermediateCerts, X509_STORE *store)
{
    X509_STORE_CTX *ctx = X509_STORE_CTX_new();
    if (X509_STORE_CTX_init(ctx, store, cert, intermediateCerts) != 1)
    {
        X509_STORE_CTX_free(ctx);
        return false;
    }
    int result = X509_verify_cert(ctx);
    X509_STORE_CTX_free(ctx);
    return result == 1;
}

// Function to print the public key in HEX format to a file
void printPublicKeyHexToFile(X509 *cert, const char *filename)
{
    EVP_PKEY *pubKey = X509_get_pubkey(cert);
    if (pubKey)
    {
        ofstream outFile(filename, ios::out);
        if (!outFile.is_open())
        {
            cerr << "Failed to open file: " << filename << endl;
            EVP_PKEY_free(pubKey);
            return;
        }
        outFile << "- Website certificate is valid." << endl;
        outFile << "- Subject Name: " << X509_NAME_oneline(X509_get_subject_name(cert), nullptr, 0) << std::endl;
        outFile << "- Issuer Name: " << X509_NAME_oneline(X509_get_issuer_name(cert), nullptr, 0) << std::endl;
        outFile << "- Subject Public Key Info:" << endl;
        int keyType = EVP_PKEY_id(pubKey);
        outFile << "+ Public Key Algorithm: " << OBJ_nid2ln(keyType) << endl;
        int keyBits = EVP_PKEY_bits(pubKey);
        outFile << "+ Public-Key: " << keyBits << " bits \n";

        BIO *bio = BIO_new(BIO_s_mem());
        PEM_write_bio_PUBKEY(bio, pubKey);
        BUF_MEM *bptr;
        BIO_get_mem_ptr(bio, &bptr);

        for (size_t i = 0; i < bptr->length; ++i)
        {
            outFile << hex << uppercase << setw(2) << setfill('0') << static_cast<unsigned int>(static_cast<unsigned char>(bptr->data[i]));
            if (i < bptr->length - 1)
            {
                if ((i + 1) % 15 == 0)
                {
                    outFile << endl;
                }
                else
                {
                    outFile << ":";
                }
            }
        }

        outFile << endl;

        outFile.close();
        BIO_free(bio);
        EVP_PKEY_free(pubKey);
    }
    else
    {
        cerr << "Failed to retrieve the public key." << endl;
    }
}

// Function to load a certificate from a file
X509 *loadCert(const char *filename, const char *format)
{
    BIO *bio = BIO_new(BIO_s_file());
    if (BIO_read_filename(bio, filename) <= 0)
    {
        cerr << "Can't open " << filename << endl;
        BIO_free(bio);
        return nullptr;
    }

    X509 *cert = nullptr;
    if (strcmp(format, "DER") == 0)
    {
        cert = d2i_X509_bio(bio, nullptr);
    }
    else if (strcmp(format, "PEM") == 0)
    {
        cert = PEM_read_bio_X509(bio, nullptr, nullptr, nullptr);
    }
    else
    {
        cerr << "Unknown format for " << filename << endl;
    }

    BIO_free(bio);
    return cert;
}

// Function to initialize OpenSSL
void initializeOpenSSL()
{
    OpenSSL_add_all_algorithms();
    ERR_load_BIO_strings();
    ERR_load_crypto_strings();
}

// Unified function to verify a certificate chain and output public key to file
int verifyAndSaveCert(const char *format, const char *rootCACertFile, const char *intermediateCertFile, const char *websiteCertFile, const char *outputFile)
{
    initializeOpenSSL();

    // Load Root CA Certificate
    X509 *rootCACert = loadCert(rootCACertFile, format);
    if (!rootCACert)
        return -1;

    // Load Intermediate Certificate
    X509 *intermediateCert = loadCert(intermediateCertFile, format);
    if (!intermediateCert)
    {
        X509_free(rootCACert);
        return -1;
    }
    STACK_OF(X509) *intermediateCerts = sk_X509_new_null();
    sk_X509_push(intermediateCerts, intermediateCert);

    // Load Website Certificate
    X509 *websiteCert = loadCert(websiteCertFile, format);
    if (!websiteCert)
    {
        sk_X509_pop_free(intermediateCerts, X509_free);
        X509_free(rootCACert);
        return -1;
    }

    // Create a certificate store and add Root CA Certificate
    X509_STORE *store = X509_STORE_new();
    X509_STORE_add_cert(store, rootCACert);

    // Verify the Website Certificate
    bool isValid = verifyCertificate(websiteCert, intermediateCerts, store);

    // Print the result
    if (isValid)
    {
        cout << "Website certificate is valid!" << endl;
        printPublicKeyHexToFile(websiteCert, outputFile);
    }
    else
    {
        cerr << "Error: Website certificate verification failed." << endl;
    }

    // Clean up
    sk_X509_pop_free(intermediateCerts, X509_free);
    X509_free(rootCACert);
    X509_free(websiteCert);
    X509_STORE_free(store);

    return isValid ? 1 : -1;
}

int main(int argc, char *argv[])
{
    if (argc != 6)
    {
        cerr << "Usage: " << argv[0] << " <format (PEM/DER)> <RootCA Cert file> <Intermediate Cert file> <Website Cert file> <Output file>" << endl;
        return -1;
    }

    const char *format = argv[1];
    const char *rootCACertFile = argv[2];
    const char *intermediateCertFile = argv[3];
    const char *websiteCertFile = argv[4];
    const char *outputFile = argv[5];

    int result = verifyAndSaveCert(format, rootCACertFile, intermediateCertFile, websiteCertFile, outputFile);
  
    return result;
}
