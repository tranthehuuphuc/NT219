
// DES-CLI.cpp
// Created by Trần Thế Hữu Phúc

// C/C++ Standard Libraries
#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include <chrono>

// Crypto++ Libraries
#include "cryptopp/base64.h"
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;

#include "cryptopp/files.h"
using CryptoPP::FileSource;
using CryptoPP::FileSink;

#include "cryptopp/filters.h"
using CryptoPP::ArraySink;
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;
using CryptoPP::AuthenticatedEncryptionFilter;
using CryptoPP::AuthenticatedDecryptionFilter;
using CryptoPP::Redirector;

#include "cryptopp/hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/secblock.h"
using CryptoPP::SecByteBlock;

// DES Libary
#include "cryptopp/des.h"
using CryptoPP::DES;

// Confidentiality only modes
#include "cryptopp/modes.h"
using CryptoPP::ECB_Mode;
using CryptoPP::CBC_Mode;
using CryptoPP::CFB_Mode;
using CryptoPP::OFB_Mode;
using CryptoPP::CTR_Mode;

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
// Save keys & iv (DER-Binary)
void SaveKey(const string& filename, const CryptoPP::SecByteBlock& bt);
void SaveIV(const string& filename, const CryptoPP::SecByteBlock& bt);

// Save keys & iv (Base64)
void SaveKeyBase64(const string& filename, const CryptoPP::SecByteBlock& bt);
void SaveIVBase64(const string& filename, const CryptoPP::SecByteBlock& bt);

// Save key & iv (HEX)
void SaveKeyHex(const string& filename, const CryptoPP::SecByteBlock& bt);
void SaveIVHex(const string& filename, const CryptoPP::SecByteBlock& bt);

// Load keys & iv (DER-Binary)
void LoadKey(const string& filename, CryptoPP::SecByteBlock& bt);
void LoadIV(const string& filename, CryptoPP::SecByteBlock& bt);

// Load keys & iv (Base64)
void LoadKeyBase64(const string& filename, CryptoPP::SecByteBlock& bt);
void LoadIVBase64(const string& filename, CryptoPP::SecByteBlock& bt);

// Load key & iv (HEX)
void LoadKeyHex(const string& filename, CryptoPP::SecByteBlock& bt);
void LoadIVHex(const string& filename, CryptoPP::SecByteBlock& bt);

/* CRYPTOGRAPHIC FUNCTIONS */
void GenerateAndSaveKeys(const char* OutputFormat, const char* FileName);
void Encryption(const char* Mode, const char* KeyFile, const char* KeyFormat, const char* PlaintextFile, const char* PlaintextFormat, const char* CiphertextFile, const char* CiphertextFormat);
void Decryption(const char* Mode, const char* KeyFile, const char* KeyFormat, const char* RecoveredFile, const char* RecoveredFormat, const char* CiphertextFile, const char* CiphertextFormat);

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
            << "   keygen <OutputFormat> <FileName>" << endl
            << "   encrypt <Mode> <KeyFile> <KeyFormat> <PlaintextFile> <PlaintextFormat> <CiphertextFile> <CiphertextFormat>" << endl
            << "   decrypt <Mode> <KeyFile> <KeyFormat> <RecoveredFile> <RecoveredFormat> <CiphertextFile> <CiphertextFormat>" << endl
            << "Note:\n   Mode: 'ECB', 'CBC', 'CFB', 'OFB', 'CTR'" << endl
            << "   OutputFormat: 'DER', 'Base64', 'HEX'" << endl
            << "   KeyFormat & CiphertextFormat: 'DER', 'Base64', 'HEX'" << endl
            << "   PlaintextFormat & RecoveredFormat: 'text', 'DER', 'Base64', 'HEX'" << endl << endl
            << "Example: " << argv[0] << " keygen Base64 key.pem" << endl;
        exit(1);
    }

    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;

    string mode = argv[1];
    if (mode == "keygen" && argc == 4) {
        start = std::chrono::high_resolution_clock::now();
        GenerateAndSaveKeys(argv[2], argv[3]);
        end = std::chrono::high_resolution_clock::now();
    }
    else if (mode == "encrypt" && argc == 9) {
        start = std::chrono::high_resolution_clock::now();
        Encryption(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
        end = std::chrono::high_resolution_clock::now();
    }
    else if (mode == "decrypt" && argc == 9) {
        start = std::chrono::high_resolution_clock::now();
        Decryption(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
        end = std::chrono::high_resolution_clock::now();
    }
    else {
        cerr << "Invalid arguments. Please read the instructions:\n";
        cerr << "Usage: " << argv[0] << " <command> [options]\nCommands:\n"
            << "   keygen <OutputFormat> <FileName>" << endl
            << "   encrypt <Mode> <KeyFile> <KeyFormat> <PlaintextFile> <PlaintextFormat> <CiphertextFile> <CiphertextFormat>" << endl
            << "   decrypt <Mode> <KeyFile> <KeyFormat> <RecoveredFile> <RecoveredFormat> <CiphertextFile> <CiphertextFormat>" << endl
            << "Note:\n   Mode: 'ECB', 'CBC', 'CFB', 'OFB', 'CTR'" << endl
            << "   OutputFormat: 'DER', 'Base64', 'HEX'" << endl
            << "   KeyFormat & CiphertextFormat: 'DER', 'Base64', 'HEX'" << endl
            << "   PlaintextFormat & RecoveredFormat: 'text', 'DER', 'Base64', 'HEX'" << endl << endl
            << "Example: " << argv[0] << " keygen Base64 key.pem" << endl;
        exit(1);
    }
    
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Execution time: " << (double)(duration.count() / 1000.0) << " ms" << endl;

    // cout << (double)(duration.count() / 1000.0);
    
    return 0;
}

/*********************************\
\*********************************/

// Generate and save keys
void GenerateAndSaveKeys(const char* OutputFormat, const char* FileName) {
    AutoSeededRandomPool prng;
    string strOutputFormat(OutputFormat);

    // Generate key & iv
    SecByteBlock key(DES::DEFAULT_KEYLENGTH);
    prng.GenerateBlock(key, key.size());

    SecByteBlock iv(DES::BLOCKSIZE);
    prng.GenerateBlock(iv, iv.size());

    //Save key & iv
    if (strOutputFormat == "DER") {
        SaveKey(FileName, key);
        SaveIV("iv.bin", iv);
    }
    else if (strOutputFormat == "Base64") {
        SaveKeyBase64(FileName, key);
        SaveIVBase64("iv.pem", iv);
    }
    else if (strOutputFormat == "HEX") {
        SaveKeyHex(FileName, key);
        SaveIVHex("iv.hex", iv);
    }
    else {
        cerr << "Unsupported key format. Please choose 'DER', 'Base64' or 'HEX'\n";
        exit(1);
    }

    cout << "Successfully generate key and iv." << endl;
}

// Encryption
void Encryption(const char* Mode, const char* KeyFile, const char* KeyFormat, const char* PlaintextFile, const char* PlaintextFormat, const char* CiphertextFile, const char* CiphertextFormat) {
    string strMode(Mode);
    string strKeyFormat(KeyFormat);
    string strPlaintextFormat(PlaintextFormat);
    string strCiphertextFormat(CiphertextFormat);

    // Load key & iv
    SecByteBlock key(DES::DEFAULT_KEYLENGTH);
    SecByteBlock iv(DES::BLOCKSIZE);
    if (strKeyFormat == "DER") {
        LoadKey(KeyFile, key);
        LoadIV("iv.bin", iv);
    }
    else if (strKeyFormat == "Base64") {
        LoadKeyBase64(KeyFile, key);
        LoadIVBase64("iv.pem", iv);
    }
    else if (strKeyFormat == "HEX") {
        LoadKeyHex(KeyFile, key);
        LoadIVHex("iv.hex", iv);
    }
    else {
        cerr << "Unsupported key format. Please choose 'DER', 'Base64' or 'HEX'\n";
        exit(1);
    }

    // Load plaintext
    string plain;
    if (strPlaintextFormat == "text") {
        FileSource fs(PlaintextFile, true, new StringSink(plain));
    }
    else if (strPlaintextFormat == "DER") {
        FileSource fs(PlaintextFile, true, new StringSink(plain));
    }
    else if (strPlaintextFormat == "Base64") {
        FileSource fs(PlaintextFile, true, new Base64Decoder(new StringSink(plain)));
    }
    else if (strPlaintextFormat == "HEX") {
        FileSource fs(PlaintextFile, true, new HexDecoder(new StringSink(plain)));
    }
    else {
        cerr << "Unsupported plain text format. Please choose 'text', 'DER', 'Base64' or 'HEX'\n";
        exit(1);
    }

    // Encryption
    string cipher;
    if (strMode == "ECB") {
        ECB_Mode< DES >::Encryption e;
        e.SetKey(key, key.size());

        StringSource ss(plain, true,
            new StreamTransformationFilter(e,
                new StringSink(cipher)
            )
        );
    }
    else if (strMode == "CBC") {
        CBC_Mode< DES >::Encryption e;
        e.SetKeyWithIV(key, key.size(), iv);

        StringSource ss(plain, true,
            new StreamTransformationFilter(e,
                new StringSink(cipher)
            )
        );
    }
    else if (strMode == "CFB") {
        CFB_Mode< DES >::Encryption e;
        e.SetKeyWithIV(key, key.size(), iv);

        StringSource ss(plain, true,
            new StreamTransformationFilter(e,
                new StringSink(cipher)
            )
        );
    }
    else if (strMode == "OFB") {
        OFB_Mode< DES >::Encryption e;
        e.SetKeyWithIV(key, key.size(), iv);

        StringSource ss(plain, true,
            new StreamTransformationFilter(e,
                new StringSink(cipher)
            )
        );
    }
    else if (strMode == "CTR") {
        CTR_Mode< DES >::Encryption e;
        e.SetKeyWithIV(key, key.size(), iv);

        StringSource ss(plain, true,
            new StreamTransformationFilter(e,
                new StringSink(cipher)
            )
        );
    }
    else {
        cerr << "Unsupported mode. Please choose: 'ECB', 'CBC', 'CFB', 'OFB', 'CTR'\n";
        exit(1);
    }

    // Save cipher
    if (strCiphertextFormat == "DER") {
        StringSource(cipher, true,
            new FileSink(CiphertextFile)
        );
    }
    else if (strCiphertextFormat == "Base64") {
        StringSource(cipher, true,
            new Base64Encoder(
                new FileSink(CiphertextFile)
            )
        );
    }
    else if (strCiphertextFormat == "HEX") {
        StringSource(cipher, true,
            new HexEncoder(
                new FileSink(CiphertextFile)
            )
        );
    }
    else {
        cerr << "Unsupported cipher text format. Please choose 'DER', 'Base64' or 'HEX'\n";
        exit(1);
    }

    cout << "Successfully encrypt plain text." << endl;
}

// Decryption
void Decryption(const char* Mode, const char* KeyFile, const char* KeyFormat, const char* RecoveredFile, const char* RecoveredFormat, const char* CiphertextFile, const char* CiphertextFormat) {
    string strMode(Mode);
    string strKeyFormat(KeyFormat);
    string strPlaintextFormat(RecoveredFormat);
    string strCiphertextFormat(CiphertextFormat);

    // Load key & iv
    SecByteBlock key(DES::DEFAULT_KEYLENGTH);
    SecByteBlock iv(DES::BLOCKSIZE);
    if (strKeyFormat == "DER") {
        LoadKey(KeyFile, key);
        LoadIV("iv.bin", iv);
    }
    else if (strKeyFormat == "Base64") {
        LoadKeyBase64(KeyFile, key);
        LoadIVBase64("iv.pem", iv);
    }
    else if (strKeyFormat == "HEX") {
        LoadKeyHex(KeyFile, key);
        LoadIVHex("iv.hex", iv);
    }
    else {
        cerr << "Unsupported key format. Please choose 'DER', 'Base64' or 'HEX'\n";
        exit(1);
    }

    // Load cipher
    string cipher;
    if (strCiphertextFormat == "DER") {
        FileSource fs(CiphertextFile, true, new StringSink(cipher));
    }
    else if (strCiphertextFormat == "Base64") {
        FileSource fs(CiphertextFile, true, new Base64Decoder(new StringSink(cipher)));
    }
    else if (strCiphertextFormat == "HEX") {
        FileSource fs(CiphertextFile, true, new HexDecoder(new StringSink(cipher)));
    }
    else {
        cerr << "Unsupported cipher text format. Please choose 'DER', 'Base64' or 'HEX'\n";
        exit(1);
    }

    // Decryption
    string recovered;
    if (strMode == "ECB") {
        ECB_Mode< DES >::Decryption d;
        d.SetKey(key, key.size());

        StringSource ss(cipher, true,
            new StreamTransformationFilter(d,
                new StringSink(recovered)
            )
        );
    }
    else if (strMode == "CBC") {
        CBC_Mode< DES >::Decryption d;
        d.SetKeyWithIV(key, key.size(), iv);

        StringSource ss(cipher, true,
            new StreamTransformationFilter(d,
                new StringSink(recovered)
            )
        );
    }
    else if (strMode == "CFB") {
        CFB_Mode< DES >::Decryption d;
        d.SetKeyWithIV(key, key.size(), iv);

        StringSource ss(cipher, true,
            new StreamTransformationFilter(d,
                new StringSink(recovered)
            )
        );
    }
    else if (strMode == "OFB") {
        OFB_Mode< DES >::Decryption d;
        d.SetKeyWithIV(key, key.size(), iv);

        StringSource ss(cipher, true,
            new StreamTransformationFilter(d,
                new StringSink(recovered)
            )
        );
    }
    else if (strMode == "CTR") {
        CTR_Mode< DES >::Decryption d;
        d.SetKeyWithIV(key, key.size(), iv);

        StringSource ss(cipher, true,
            new StreamTransformationFilter(d,
                new StringSink(recovered)
            )
        );
    }
    else {
        cerr << "Unsupported mode. Please choose: 'ECB', 'CBC', 'CFB', 'OFB', 'CTR'\n";
        exit(1);
    }

    // Save recovered
    if (strPlaintextFormat == "text") {
        StringSource(recovered, true,
            new FileSink(RecoveredFile)
        );
    }
    else if (strPlaintextFormat == "DER") {
        StringSource(recovered, true,
            new FileSink(RecoveredFile)
        );
    }
    else if (strPlaintextFormat == "Base64") {
        StringSource(recovered, true,
            new Base64Encoder(
                new FileSink(RecoveredFile)
            )
        );
    }
    else if (strPlaintextFormat == "HEX") {
        StringSource(recovered, true,
            new HexEncoder(
                new FileSink(RecoveredFile)
            )
        );
    }
    else {
        cerr << "Unsupported recovery text format. Please choose 'text', 'DER', 'Base64' or 'HEX'\n";
        exit(1);
    }

    cout << "Successfully decrypt cipher text." << endl;
}


// Save key & iv (DER-Binary)
void SaveKey(const string& filename, const CryptoPP::SecByteBlock& bt) {
    StringSource ss(bt, bt.size(), true,
        new FileSink(filename.c_str())
    ); // StringSource
}

void SaveIV(const string& filename, const CryptoPP::SecByteBlock& bt) {
    StringSource ss(bt, bt.size(), true,
        new FileSink(filename.c_str())
    ); // StringSource
}


// Save key & iv (Base64)
void SaveKeyBase64(const string& filename, const CryptoPP::SecByteBlock& bt) {
    StringSource ss(bt, bt.size(), true,
        new Base64Encoder(
            new FileSink(filename.c_str()) 
        ) // Base64Encoder
    ); // StringSource
}

void SaveIVBase64(const string& filename, const CryptoPP::SecByteBlock& bt) {
    StringSource ss(bt, bt.size(), true, 
        new Base64Encoder(
            new FileSink(filename.c_str()) 
        ) // Base64Encoder
    ); // StringSource
}

// Save key & iv (HEX)
void SaveKeyHex(const string& filename, const CryptoPP::SecByteBlock& bt) {
    StringSource ss(bt, bt.size(), true,
        new HexEncoder(
            new FileSink(filename.c_str())
        ) // HexEncoder
    ); // StringSource
}

void SaveIVHex(const string& filename, const CryptoPP::SecByteBlock& bt) {
    StringSource ss(bt, bt.size(), true,
        new HexEncoder(
            new FileSink(filename.c_str())
        ) // HexEncoder
    ); // StringSource
}


// Load key & iv (DER-Binary)
void LoadKey(const string& filename, SecByteBlock& bt) {
    FileSource fs(filename.c_str(), true, 
        new ArraySink(bt, bt.size()) 
    ); // FileSource
}

void LoadIV(const string& filename, CryptoPP::SecByteBlock& bt) {
    FileSource fs(filename.c_str(), true, 
        new ArraySink(bt, bt.size())
    ); // FileSource
}

// Load key & iv (Base64)
void LoadKeyBase64(const string& filename, CryptoPP::SecByteBlock& bt) {
    FileSource fs(filename.c_str(), true,  
        new Base64Decoder( 
            new ArraySink(bt, bt.size())
        ) /*Base64Decoder*/
    ); // FileSource
}

void LoadIVBase64(const string& filename, CryptoPP::SecByteBlock& bt) {
    FileSource fs(filename.c_str(), true, 
        new Base64Decoder(
            new ArraySink(bt, bt.size())
        ) /*Base64Decoder*/
    ); // FileSource
}

// Load key & iv (HEX)
void LoadKeyHex(const string& filename, CryptoPP::SecByteBlock& bt) {
    FileSource fs(filename.c_str(), true, 
        new HexDecoder(
            new ArraySink(bt, bt.size())
        ) /*HexDecoder*/
    ); // FileSource
}

void LoadIVHex(const string& filename, CryptoPP::SecByteBlock& bt) {
    FileSource fs(filename.c_str(), true, 
        new HexDecoder(
            new ArraySink(bt, bt.size())
        ) /*HexDecoder*/
    ); // FileSource
}