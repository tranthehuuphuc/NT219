#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/sha.h>
#include <chrono>

using namespace std;

bool key_gen(const char *filePrivate, const char *filePublic, const char *format)
{
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    string strFormat(format);
    EVP_PKEY *pkey = nullptr;
    EVP_PKEY_CTX *pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL);

    if (!EVP_PKEY_keygen_init(pctx))
    {
        cerr << "Failed to initialize key generation context." << endl;
        EVP_PKEY_CTX_free(pctx);
        return false;
    }

    if (!EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pctx, NID_secp384r1))
    {
        cerr << "Failed to set curve for key generation." << endl;
        EVP_PKEY_CTX_free(pctx);
        return false;
    }

    if (EVP_PKEY_keygen(pctx, &pkey) <= 0)
    {
        cerr << "Failed to generate key pair." << endl;
        EVP_PKEY_CTX_free(pctx);
        return false;
    }

    if (strFormat == "DER")
    {
        // Save private key in DER format
        BIO *bioPrivate = BIO_new_file(filePrivate, "wb");
        if (!bioPrivate)
        {
            cerr << "Failed to open private key file for writing." << endl;
            EVP_PKEY_free(pkey);
            EVP_PKEY_CTX_free(pctx);
            return false;
        }
        if (!i2d_PrivateKey_bio(bioPrivate, pkey))
        {
            cerr << "Failed to write private key in DER format." << endl;
            BIO_free(bioPrivate);
            EVP_PKEY_free(pkey);
            EVP_PKEY_CTX_free(pctx);
            return false;
        }
        BIO_free(bioPrivate);

        // Save public key in DER format
        BIO *bioPublic = BIO_new_file(filePublic, "wb");
        if (!bioPublic)
        {
            cerr << "Failed to open public key file for writing." << endl;
            EVP_PKEY_free(pkey);
            EVP_PKEY_CTX_free(pctx);
            return false;
        }
        if (!i2d_PUBKEY_bio(bioPublic, pkey))
        {
            cerr << "Failed to write public key in DER format." << endl;
            BIO_free(bioPublic);
            EVP_PKEY_free(pkey);
            EVP_PKEY_CTX_free(pctx);
            return false;
        }
        BIO_free(bioPublic);
    }
    else if (strFormat == "PEM")
    {
        // Save private key in PEM format
        BIO *bioPrivate = BIO_new_file(filePrivate, "w");
        if (!bioPrivate)
        {
            cerr << "Failed to open private key file for writing." << endl;
            EVP_PKEY_free(pkey);
            EVP_PKEY_CTX_free(pctx);
            return false;
        }
        if (!PEM_write_bio_PrivateKey(bioPrivate, pkey, NULL, NULL, 0, NULL, NULL))
        {
            cerr << "Failed to write private key in PEM format." << endl;
            BIO_free(bioPrivate);
            EVP_PKEY_free(pkey);
            EVP_PKEY_CTX_free(pctx);
            return false;
        }
        BIO_free(bioPrivate);

        // Save public key in PEM format
        BIO *bioPublic = BIO_new_file(filePublic, "w");
        if (!bioPublic)
        {
            cerr << "Failed to open public key file for writing." << endl;
            EVP_PKEY_free(pkey);
            EVP_PKEY_CTX_free(pctx);
            return false;
        }
        if (!PEM_write_bio_PUBKEY(bioPublic, pkey))
        {
            cerr << "Failed to write public key in PEM format." << endl;
            BIO_free(bioPublic);
            EVP_PKEY_free(pkey);
            EVP_PKEY_CTX_free(pctx);
            return false;
        }
        BIO_free(bioPublic);
    }
    else
    {
        cerr << "Unsupported format specified." << endl;
        EVP_PKEY_free(pkey);
        EVP_PKEY_CTX_free(pctx);
        return false;
    }

    EVP_PKEY_free(pkey);
    EVP_PKEY_CTX_free(pctx);
    EVP_cleanup();
    ERR_free_strings();
    return true;
}
int sign(const char *filePrivate, const char *filename, const char *signFile)
{
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    EVP_PKEY *privateKey = nullptr;
    BIO *bio = BIO_new(BIO_s_file());

    if (!bio)
    {
        std::cerr << "Failed to create BIO." << std::endl;
        return 1;
    }

    if (BIO_read_filename(bio, filePrivate) <= 0)
    {
        std::cerr << "Failed to read private key file." << std::endl;
        BIO_free(bio);
        return 1;
    }

    privateKey = PEM_read_bio_PrivateKey(bio, NULL, NULL, NULL);
    if (!privateKey)
    {
        // Reset BIO and try reading as DER format
        BIO_reset(bio);
        privateKey = d2i_PrivateKey_bio(bio, NULL);
    }

    BIO_free(bio);

    if (!privateKey)
    {
        std::cerr << "Failed to read private key." << std::endl;
        return 1;
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    ifstream inFile(filename, ios::binary);
    if (!inFile)
    {
        cerr << "Failed to open input file." << endl;
        EVP_PKEY_free(privateKey);
        return 2;
    }
    vector<unsigned char> fileData((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    SHA256(&fileData[0], fileData.size(), hash);

    EVP_MD_CTX *mdCtx = EVP_MD_CTX_new();
    if (!mdCtx)
    {
        cerr << "Failed to create message digest context." << endl;
        EVP_PKEY_free(privateKey);
        return 3;
    }

    if (!EVP_SignInit(mdCtx, EVP_sha256()))
    {
        cerr << "Failed to initialize signing." << endl;
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(privateKey);
        return 3;
    }

    if (!EVP_SignUpdate(mdCtx, hash, SHA256_DIGEST_LENGTH))
    {
        cerr << "Failed to update signing." << endl;
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(privateKey);
        return 3;
    }

    unsigned int sigLen;
    unsigned char *sig = new unsigned char[EVP_PKEY_size(privateKey)];
    if (!EVP_SignFinal(mdCtx, sig, &sigLen, privateKey))
    {
        cerr << "Failed to finalize signing." << endl;
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(privateKey);
        delete[] sig;
        return 3;
    }

    ofstream outFile(signFile, ios::binary);
    if (!outFile)
    {
        cerr << "Failed to open signature file for writing." << endl;
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(privateKey);
        delete[] sig;
        return 4;
    }
    outFile.write(reinterpret_cast<const char *>(sig), sigLen);
    outFile.close();

    EVP_MD_CTX_free(mdCtx);
    EVP_PKEY_free(privateKey);
    delete[] sig;
    EVP_cleanup();
    ERR_free_strings();
    return 0;
}
int verify(const char *filePublic, const char *filename, const char *signFile)
{
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    BIO *bio = BIO_new_file(filePublic, "rb");
    if (!bio)
    {
        cerr << "Failed to open public key file." << endl;
        return 1;
    }

    EVP_PKEY *publicKey = PEM_read_bio_PUBKEY(bio, NULL, NULL, NULL);
    if (!publicKey)
    {
        // Reset BIO and try reading as DER format
        BIO_reset(bio);
        publicKey = d2i_PUBKEY_bio(bio, NULL);
    }

    if (!publicKey)
    {
        cerr << "Failed to read public key." << endl;
        BIO_free(bio);
        return 1;
    }
    BIO_free(bio);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    ifstream inFile(filename, ios::binary);
    if (!inFile)
    {
        cerr << "Failed to open input file." << endl;
        EVP_PKEY_free(publicKey);
        return 2;
    }
    vector<unsigned char> fileData((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    SHA256(&fileData[0], fileData.size(), hash);

    EVP_MD_CTX *mdCtx = EVP_MD_CTX_new();
    if (!mdCtx)
    {
        cerr << "Failed to create message digest context." << endl;
        EVP_PKEY_free(publicKey);
        return 3;
    }

    if (!EVP_VerifyInit(mdCtx, EVP_sha256()))
    {
        cerr << "Failed to initialize verification." << endl;
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(publicKey);
        return 3;
    }

    if (!EVP_VerifyUpdate(mdCtx, hash, SHA256_DIGEST_LENGTH))
    {
        cerr << "Failed to update verification." << endl;
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(publicKey);
        return 3;
    }

    ifstream sigFile(signFile, ios::binary);
    if (!sigFile)
    {
        cerr << "Failed to open signature file." << endl;
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(publicKey);
        return 4;
    }
    sigFile.seekg(0, ios::end);
    size_t sigLen = sigFile.tellg();
    sigFile.seekg(0, ios::beg);
    vector<unsigned char> signature(sigLen);
    sigFile.read(reinterpret_cast<char *>(&signature[0]), sigLen);
    sigFile.close();

    int verifyResult = EVP_VerifyFinal(mdCtx, &signature[0], static_cast<int>(sigLen), publicKey);
    if (verifyResult != 1)
    {
        cerr << "Signature verification failed." << endl;
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(publicKey);
        return 5;
    }

    EVP_MD_CTX_free(mdCtx);
    EVP_PKEY_free(publicKey);
    EVP_cleanup();
    ERR_free_strings();
    return 0;
}
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Usage:" << endl;
        cerr << "  keygen <private_key_file> <public_key_file> <format (PEM/DER)>" << endl;
        cerr << "  sign <private_key_file> <input_file> <signature_file>" << endl;
        cerr << "  verify <public_key_file> <input_file> <signature_file>" << endl;
        return -1;
    }

    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    string command = argv[1];

    if (command == "keygen")
    {
        if (argc != 5)
        {
            cerr << "Usage: keygen <private_key_file> <public_key_file> <format (PEM/DER)>" << endl;
            return -1;
        }
        const char *filePrivate = argv[2];
        const char *filePublic = argv[3];
        const char *format = argv[4];

        bool result = key_gen(filePrivate, filePublic, format);
        if (result)
        {
            cout << "Key generation successful." << endl;
        }
        else
        {
            cerr << "Key generation failed." << endl;
            return -1;
        }
    }
    else if (command == "sign")
    {
        if (argc != 5)
        {
            cerr << "Usage: sign <private_key_file> <input_file> <signature_file>" << endl;
            return -1;
        }
        const char *filePrivate = argv[2];
        const char *filename = argv[3];
        const char *signFile = argv[4];
        int result = -1; 

        auto start = std::chrono::high_resolution_clock::now();
            result = sign(filePrivate, filename, signFile);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        
        if (result == 0)
        {
            cout << (double)(duration.count() / 1000.0);
        }
        else
        {
            return -1;
        }
    }
    else if (command == "verify")
    {
        if (argc != 5)
        {
            cerr << "Usage: verify <public_key_file> <input_file> <signature_file>" << endl;
            return -1;
        }
        const char *filePublic = argv[2];
        const char *filename = argv[3];
        const char *signFile = argv[4];

        int result = -1; 

        auto start = std::chrono::high_resolution_clock::now();
            result = verify(filePublic, filename, signFile);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

        if (result == 0)
        {
            cout << (double)(duration.count() / 1000.0);
        }
        else
        {
            return -1;
        }
    }
    else
    {
        cerr << "Unknown command: " << command << endl;
        return -1;
    }

    EVP_cleanup();
    ERR_free_strings();
    return 0;
}
