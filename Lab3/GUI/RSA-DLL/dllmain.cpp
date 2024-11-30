// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

/*********************************\
\*********************************/

#ifndef BUILD_DLL
#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif
#else
#define EXPORT
#endif

extern "C" {
    EXPORT void GenerateAndSaveRSAKeys(const int keySize, const char* format, const char* privateKeyFile, const char* publicKeyFile);
    EXPORT void RSAEncryption(const char* format, const char* publicKeyFile, const char* PlaintextFile, const char* CiphertFile);
    EXPORT void RSADecryption(const char* format, const char* secretKeyFile, const char* PlaintextFile, const char* ciphertFile);
}

/*********************************\
\*********************************/


// RSA-CLI.cpp
// Created by Trần Thế Hữu Phúc

// C/C++ Standard Libraries
#include <assert.h>

#include <chrono>

#include <iostream>

#include <stdio.h>
using std::cout;
using std::cerr;
using std::endl;

#include <stdexcept>
using std::runtime_error;

#include <string>
using std::string;

#include <exception>
using std::exception;

// Crypto++ Libraries
#include "cryptopp/base64.h"
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;

#include "cryptopp/cryptlib.h"
using CryptoPP::BufferedTransformation;
using CryptoPP::DecodingResult;
using CryptoPP::Exception;
using CryptoPP::PrivateKey;
using CryptoPP::PublicKey;

#include "cryptopp/files.h"
using CryptoPP::FileSource;
using CryptoPP::FileSink;

#include "cryptopp/filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::PK_EncryptorFilter;
using CryptoPP::PK_DecryptorFilter;

#include "cryptopp/hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "cryptopp/integer.h"
using CryptoPP::Integer;

#include "cryptopp/modarith.h"
using CryptoPP::ModularArithmetic;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/queue.h"
using CryptoPP::ByteQueue;

#include "cryptopp/rsa.h"
using CryptoPP::RSA;
using CryptoPP::InvertibleRSAFunction;
using CryptoPP::RSAES_OAEP_SHA_Encryptor;
using CryptoPP::RSAES_OAEP_SHA_Decryptor;

#include "cryptopp/sha.h"
using CryptoPP::SHA1;

#include "cryptopp/secblock.h"
using CryptoPP::SecByteBlock;

// Define platform-specific features
#ifdef __APPLE__
#include <sys/stat.h>
#include <sys/types.h>
#elif __linux__
#include <sys/stat.h>
#include <sys/types.h>
#elif _WIN32
#include <windows.h>
#include <direct.h>
#endif

// Define functions
// Save RSA keys (DER-Binary)
void Save(const string& filename, const BufferedTransformation& bt);
void SavePrivateKey(const string& filename, const PrivateKey& key);
void SavePublicKey(const string& filename, const PublicKey& key);

// Save RSA keys (Base64)
void SaveBase64(const string& filename, const BufferedTransformation& bt);
void SaveBase64PrivateKey(const string& filename, const PrivateKey& key);
void SaveBase64PublicKey(const string& filename, const PublicKey& key);

// Save RSA keys (HEX)
void SaveHex(const string& filename, const BufferedTransformation& bt);
void SaveHexPrivateKey(const string& filename, const PrivateKey& key);
void SaveHexPublicKey(const string& filename, const PublicKey& key);

// Load RSA keys (DER-Binary)
void Load(const string& filename, BufferedTransformation& bt);
void LoadPrivateKey(const string& filename, PrivateKey& key);
void LoadPublicKey(const string& filename, PublicKey& key);

// Load RSA keys (Base64)
void LoadBase64(const string& filename, BufferedTransformation& bt);
void LoadBase64PrivateKey(const string& filename, PrivateKey& key);
void LoadBase64PublicKey(const string& filename, PublicKey& key);

// Load RSA keys (HEX)
void LoadHex(const string& filename, BufferedTransformation& bt);
void LoadHexPrivateKey(const string& filename, PrivateKey& key);
void LoadHexPublicKey(const string& filename, PublicKey& key);

/* CRYPTOGRAPHIC FUNCTIONS */
void GenerateAndSaveRSAKeys(const int keySize, const char* format, const char* privateKeyFile, const char* publicKeyFile);
void RSAEncryption(const char* format, const char* publicKeyFile, const char* PlaintextFile, const char* CiphertFile);
void RSADecryption(const char* format, const char* secretKeyFile, const char* PlaintextFile, const char* ciphertFile);

/*********************************\
\*********************************/

int main(int argc, char* argv[]) {
    // Set UTF-8 Encoding
#ifdef __APPLE__
    std::locale::global(std::locale("en_US.UTF-8"));
#elif __linux__
    std::locale::global(std::locale("C.utf8"));
#elif _WIN32
    // Set console code page to UTF-8 on Windows C.utf8, CP_UTF8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    std::ios_base::sync_with_stdio(false);

    if (argc < 2) {
        cerr << "Invalid arguments. Please read the instructions:\n";
        cerr << "Usage: " << argv[0] << " <command> [options]\nCommands:\n"
            << "   keygen <KeySize> <Format> <privateKeyFile> <publicKeyFile>" << endl
            << "   encrypt <Format> <publicKeyFile> <plainTextFile> <cipherTextFile>" << endl
            << "   decrypt <Format> <privateKeyFile> <recoveredFile> <cipherTextFile>" << endl
            << "Note:\n   KeySize is the size of the key in bits (1024, 2048, 3072, 4096,...)" << endl
            << "   Supported format for Key: 'DER', 'Base64', 'HEX'" << endl
            << "Example:\n   " << argv[0] << " keygen 4096 Base64 pri.pem pub.pem" << endl;
        exit(1);
    }

    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;

    string mode = argv[1];
    if (mode == "keygen" && argc == 6) {
        int keySize = std::stoi(argv[2]);
        start = std::chrono::high_resolution_clock::now();
        GenerateAndSaveRSAKeys(keySize, argv[3], argv[4], argv[5]);
        end = std::chrono::high_resolution_clock::now();
    }
    else if (mode == "encrypt" && argc == 6) {
        start = std::chrono::high_resolution_clock::now();
        RSAEncryption(argv[2], argv[3], argv[4], argv[5]);
        end = std::chrono::high_resolution_clock::now();
    }
    else if (mode == "decrypt" && argc == 6) {
        start = std::chrono::high_resolution_clock::now();
        RSADecryption(argv[2], argv[3], argv[4], argv[5]);
        end = std::chrono::high_resolution_clock::now();
    }
    else {
        cerr << "Invalid arguments. Please read the instructions:\n";
        cerr << "Usage: " << argv[0] << " <command> [options]\nCommands:\n"
            << "   keygen <KeySize> <Format> <privateKeyFile> <publicKeyFile>" << endl
            << "   encrypt <Format> <publicKeyFile> <plainTextFile> <cipherTextFile>" << endl
            << "   decrypt <Format> <privateKeyFile> <recoveredFile> <cipherTextFile>" << endl
            << "Note:\n   KeySize is the size of the key in bits (1024, 2048, 3072, 4096,...)" << endl
            << "   Supported format for Key: 'DER', 'Base64', 'HEX'" << endl
            << "Example:\n   " << argv[0] << " keygen 4096 Base64 pri.pem pub.pem" << endl;
        exit(1);
    }

    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // cout << "Time: " << (double)(duration.count() / 1000.0) << " miliseconds" << endl;
    cout << (double)(duration.count() / 1000.0);

    return 0;
}

/*********************************\
\*********************************/

// Generate and save RSA keys
void GenerateAndSaveRSAKeys(const int keySize, const char* format, const char* privateKeyFile, const char* publicKeyFile) {
    string strFormat(format);
    string strPrivateKeyFile(privateKeyFile);
    string strPublicKeyFile(publicKeyFile);

    // Generate keys
    AutoSeededRandomPool rnd;
    RSA::PrivateKey rsaPrivate;
    rsaPrivate.GenerateRandomWithKeySize(rnd, keySize);
    RSA::PublicKey rsaPublic(rsaPrivate);

    // Save keys
    if (strFormat == "DER") {
        SavePrivateKey(strPrivateKeyFile, rsaPrivate);
        SavePublicKey(strPublicKeyFile, rsaPublic);
    }
    else if (strFormat == "Base64") {
        SaveBase64PrivateKey(strPrivateKeyFile, rsaPrivate);
        SaveBase64PublicKey(strPublicKeyFile, rsaPublic);
    }
    else if (strFormat == "HEX") {
        SaveHexPrivateKey(strPrivateKeyFile, rsaPrivate);
        SaveHexPublicKey(strPublicKeyFile, rsaPublic);
    }
    else {
        cerr << "Unsupported format. Please choose 'DER', 'Base64' or 'HEX' ";
    }

    Integer modul1 = rsaPrivate.GetModulus(); // modul n
    Integer prime1 = rsaPrivate.GetPrime1(); // prime p
    Integer prime2 = rsaPrivate.GetPrime2();  // prime q

    Integer modul2 = rsaPublic.GetModulus(); // modul n
    Integer SK = rsaPrivate.GetPrivateExponent(); // secret exponent d; 
    Integer PK = rsaPublic.GetPublicExponent(); // public exponent e; 

    // cout << "Public modul (from secret key) = " << modul1 << endl << endl;
    // cout << "Public modul (from public key) = " << modul2 << endl << endl;
    // cout << "Secret exponent d = " << SK << endl << endl;
    // cout << "Prime number p = " << std::hex << prime1 << std::dec << endl << endl;
    // cout << "Prime number q = " << std::hex << prime2 << std::dec << endl << endl;
    // cout << "Public exponent e = " << PK << endl << endl;

    RSA::PrivateKey r1, r2;
    r1.GenerateRandomWithKeySize(rnd, 3072);

    SavePrivateKey("rsa-roundtrip.key", r1);
    LoadPrivateKey("rsa-roundtrip.key", r2);

    r1.Validate(rnd, 3);
    r2.Validate(rnd, 3);

    if (r1.GetModulus() != r2.GetModulus() ||
        r1.GetPublicExponent() != r2.GetPublicExponent() ||
        r1.GetPrivateExponent() != r2.GetPrivateExponent())
    {
        throw runtime_error("key data did not round trip");
    }

    // cout << "Successfully generated and saved RSA keys" << endl;
}

// RSA Encryption
void RSAEncryption(const char* format, const char* publicKeyFile, const char* PlaintextFile, const char* CiphertFile) {
    AutoSeededRandomPool rng;
    string strFormat(format);
    string strPublicKeyFile(publicKeyFile);

    // Load public key
    RSA::PublicKey publicKey;
    if (strFormat == "DER") {
        LoadPublicKey(strPublicKeyFile, publicKey);
    }
    else if (strFormat == "Base64") {
        LoadBase64PublicKey(strPublicKeyFile, publicKey);
    }
    else if (strFormat == "HEX") {
        LoadHexPublicKey(strPublicKeyFile, publicKey);
    }
    else {
        cerr << "Unsupported format. Please choose 'DER', 'Base64' or 'HEX' ";
        exit(1);
    }

    // Load plain text
    string plain, cipher;
    FileSource file(PlaintextFile, true, new StringSink(plain));

    // Run Encryption and save file
    // Encrypt with OAEF padding, SHA1
    RSAES_OAEP_SHA_Encryptor e(publicKey);

    // Run encrypt function and save to file
    StringSource string(plain, true,
        new PK_EncryptorFilter(rng, e,
            new Base64Encoder(
                new FileSink(CiphertFile)
            ) // Base64Encoder
        ) // PK_EncryptorFilter
    ); // StringSource

    // cout << "Successfully encrypt plain text." << endl;
}

// RSA Decryption
void RSADecryption(const char* format, const char* secretKeyFile, const char* PlaintextFile, const char* ciphertFile) {
    AutoSeededRandomPool rng;
    string strFormat(format);
    string strSecretKeyFile(secretKeyFile);

    RSA::PrivateKey PrivateKey;
    // Load private key
    if (strFormat == "DER") {
        LoadPrivateKey(strSecretKeyFile, PrivateKey);
    }
    else if (strFormat == "Base64") {
        LoadBase64PrivateKey(strSecretKeyFile, PrivateKey);
    }
    else if (strFormat == "HEX") {
        LoadHexPrivateKey(strSecretKeyFile, PrivateKey);
    }
    else {
        cerr << "Unsupported format. Please choose 'DER', 'Base64' or 'HEX' ";
        exit(1);
    }

    // Load cipher text
    string plain, cipher;
    FileSource file(ciphertFile, true,
        new Base64Decoder(
            new StringSink(cipher)
        ) // Base64Decoder
    ); // FileSource

    // Run Decryption and save file
    // Decrypt with OAEF padding, SHA1
    RSAES_OAEP_SHA_Decryptor d(PrivateKey);

    // Run decrypt function and save to file
    StringSource string(cipher, true,
        new PK_DecryptorFilter(rng, d,
            new FileSink(PlaintextFile)
        ) // PK_DecryptorFilter
    ); // StringSource

    // cout << "Successfully decrypt cipher text." << endl;
}

// Save keys (DER-Binary)
void Save(const string& filename, const BufferedTransformation& bt) {
    FileSink file(filename.c_str());

    bt.CopyTo(file);
    file.MessageEnd();
}

void SavePrivateKey(const string& filename, const PrivateKey& key) {
    ByteQueue queue;
    key.Save(queue);

    Save(filename, queue);
}

void SavePublicKey(const string& filename, const PublicKey& key) {
    ByteQueue queue;
    key.Save(queue);

    Save(filename, queue);
}

// Save keys (Base64)
void SaveBase64(const string& filename, const BufferedTransformation& bt) {
    Base64Encoder encoder;

    bt.CopyTo(encoder);
    encoder.MessageEnd();

    Save(filename, encoder);
}

void SaveBase64PrivateKey(const string& filename, const PrivateKey& key) {
    ByteQueue queue;
    key.Save(queue);

    SaveBase64(filename, queue);
}

void SaveBase64PublicKey(const string& filename, const PublicKey& key) {
    ByteQueue queue;
    key.Save(queue);

    SaveBase64(filename, queue);
}

// Save keys (HEX)
void SaveHex(const string& filename, const BufferedTransformation& bt) {
    HexEncoder encoder;

    bt.CopyTo(encoder);
    encoder.MessageEnd();

    Save(filename, encoder);
}

void SaveHexPrivateKey(const string& filename, const PrivateKey& key) {
    ByteQueue queue;
    key.Save(queue);

    SaveHex(filename, queue);
}

void SaveHexPublicKey(const string& filename, const PublicKey& key) {
    ByteQueue queue;
    key.Save(queue);

    SaveHex(filename, queue);
}

// Load keys (DER-Binary)
void Load(const string& filename, BufferedTransformation& bt) {
    FileSource file(filename.c_str(), true /*pumpAll*/);

    file.TransferTo(bt);
    bt.MessageEnd();
}

void LoadPrivateKey(const string& filename, PrivateKey& key) {
    ByteQueue queue;

    Load(filename, queue);
    key.Load(queue);
}

void LoadPublicKey(const string& filename, PublicKey& key) {
    ByteQueue queue;

    Load(filename, queue);
    key.Load(queue);
}

// Load keys (Base64)
void LoadBase64(const string& filename, BufferedTransformation& bt) {
    Base64Decoder decoder;

    Load(filename, decoder);

    decoder.TransferTo(bt);
    bt.MessageEnd();
}

void LoadBase64PrivateKey(const string& filename, PrivateKey& key) {
    ByteQueue queue;

    LoadBase64(filename, queue);
    key.Load(queue);
}

void LoadBase64PublicKey(const string& filename, PublicKey& key) {
    ByteQueue queue;

    LoadBase64(filename, queue);
    key.Load(queue);
}

// Load keys (HEX)
void LoadHex(const string& filename, BufferedTransformation& bt) {
    HexDecoder decoder;

    Load(filename, decoder);

    decoder.TransferTo(bt);
    bt.MessageEnd();
}

void LoadHexPrivateKey(const string& filename, PrivateKey& key) {
    ByteQueue queue;

    LoadHex(filename, queue);
    key.Load(queue);
}

void LoadHexPublicKey(const string& filename, PublicKey& key) {
    ByteQueue queue;

    LoadHex(filename, queue);
    key.Load(queue);
}