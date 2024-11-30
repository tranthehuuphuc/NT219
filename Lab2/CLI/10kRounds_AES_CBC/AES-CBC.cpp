
// AES-CLI.cpp
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

// AES Libary
#include "cryptopp/aes.h"
using CryptoPP::AES;

// Confidentiality only modes
#include "cryptopp/modes.h"
using CryptoPP::ECB_Mode;
using CryptoPP::CBC_Mode;
using CryptoPP::CFB_Mode;
using CryptoPP::OFB_Mode;
using CryptoPP::CTR_Mode;

#include "cryptopp/xts.h"
using CryptoPP::XTS;

// Confidentiality and Authentication modes
#include "cryptopp/ccm.h"
using CryptoPP::CCM;

#include "cryptopp/gcm.h"
using CryptoPP::GCM;

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

// Get key size
size_t getKeySize(const string& FileName, const string& KeyFormat);

/* CRYPTOGRAPHIC FUNCTIONS */
void GenerateAndSaveKeys(const int KeySize, const char* KeyFile, const char* IVFile);
void Encryption(const char* KeyFile, const char* IVFile, const char* PlaintextFile, const char* CiphertextFile);
void Decryption(const char* KeyFile, const char* IVFile,  const char* CiphertextFile, const char* RecoveredFile);

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
        std::cerr << "Usage: " << argv[0] << " <command> [options]\n"
        << "Command:\n" 
        << "\t keygen <Key_Length> <Key_File> <IV_File>\n"
        << "\t encrypt <Key_File> <IV_File> <Plaintext_File> <Ciphertext_File>\n"
        << "\t decrypt <Key_File> <IV_File> <Ciphertext_File> <Recovered_File>\n";
        return 1;
    }

    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;

    string mode = argv[1];
    if (mode == "keygen" && argc == 5) {
        int KeySize = std::stoi(argv[2]);
        if (KeySize != 128 && KeySize != 192 && KeySize != 256) {
            cerr << "Invalid key size. Please choose 128, 192, or 256\n";
            exit(1);
        }
        KeySize /= 8; // Convert bits to bytes

        start = std::chrono::high_resolution_clock::now();
        GenerateAndSaveKeys(KeySize, argv[3], argv[4]);
        end = std::chrono::high_resolution_clock::now();
    }
    else if (mode == "encrypt" && argc == 6) {
        start = std::chrono::high_resolution_clock::now();
        Encryption(argv[2], argv[3], argv[4], argv[5]);
        end = std::chrono::high_resolution_clock::now();
    }
    else if (mode == "decrypt" && argc == 6) {
        start = std::chrono::high_resolution_clock::now();
        Decryption(argv[2], argv[3], argv[4], argv[5]);
        end = std::chrono::high_resolution_clock::now();
    }
    else {
        cerr << "Invalid arguments. Please read the instructions:\n";
        std::cerr << "Usage: " << argv[0] << " <command> [options]\n"
        << "Command:\n" 
        << "\t keygen <Key_Length> <Key_File> <IV_File>\n"
        << "\t encrypt <Key_File> <IV_File> <Plaintext_File> <Ciphertext_File>\n"
        << "\t decrypt <Key_File> <IV_File> <Ciphertext_File> <Recovered_File>\n";
        return 1;
    }
    
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //cout << "Execution time: " << (double)(duration.count() / 1000.0) << " ms" << endl;

    cout << (double)(duration.count() / 1000.0);
    
    return 0;
}

/*********************************\
\*********************************/

// Generate and save keys
void GenerateAndSaveKeys(const int KeySize, const char* KeyFile, const char* IVFile) {
    AutoSeededRandomPool prng;

    // Generate key & iv
    SecByteBlock key(KeySize);
    prng.GenerateBlock(key, key.size());

    SecByteBlock iv(AES::BLOCKSIZE);
    prng.GenerateBlock(iv, iv.size());

    //Save key & iv
    SaveKey(KeyFile, key);
    SaveIV(IVFile, iv);
}

// Encryption
void Encryption(const char* KeyFile, const char* IVFile, const char* PlaintextFile, const char* CiphertextFile) {
    // Get key size
    size_t KeySize = getKeySize(KeyFile, "DER");

    // Load key & iv
    SecByteBlock key(KeySize);
    SecByteBlock iv(AES::BLOCKSIZE);

    LoadKey(KeyFile, key);
    LoadIV(IVFile, iv);

    // Load plaintext
    string plain;
    FileSource fs(PlaintextFile, true, new StringSink(plain));

    // Encryption
    string cipher;
    CBC_Mode< AES >::Encryption e;
    e.SetKeyWithIV(key, key.size(), iv);

    StringSource ss(plain, true,
        new StreamTransformationFilter(e,
            new StringSink(cipher)
        )
    );

    // Save cipher
    StringSource(cipher, true,
        new FileSink(CiphertextFile)
    );
}

// Decryption
void Decryption(const char* KeyFile, const char* IVFile,  const char* CiphertextFile, const char* RecoveredFile) {
    // Get key size
    size_t KeySize = getKeySize(KeyFile, "DER");

    // Load key & iv
    SecByteBlock key(KeySize);
    SecByteBlock iv(AES::BLOCKSIZE);

    LoadKey(KeyFile, key);
    LoadIV(IVFile, iv);
    
    // Load cipher
    string cipher;
    FileSource fs(CiphertextFile, true, new StringSink(cipher));

    // Decryption
    string recovered;
    CBC_Mode< AES >::Decryption d;
    d.SetKeyWithIV(key, key.size(), iv);

    StringSource ss(cipher, true,
        new StreamTransformationFilter(d,
            new StringSink(recovered)
        )
    );
    
    // Save recovered
    StringSource(recovered, true,
        new FileSink(RecoveredFile)
    );
}

// Get key size
size_t getKeySize(const string& FileName, const string& KeyFormat) {
    std::ifstream file(FileName, std::ios::binary);

    size_t KeySize = 0;

    // Read file
    std::stringstream Key;
    Key << file.rdbuf();
    file.close();

    if (KeyFormat == "DER") {
        KeySize = Key.str().size();
    }
    else if (KeyFormat == "Base64") {
        string Base64Key;

        // Decode the Base64 Encoded Key
        StringSource ss(Key.str(), true,
            new Base64Decoder(
                new StringSink(Base64Key)
            ) // Base64Decoder
        ); // StringSource
        KeySize = Base64Key.size();
    }
    else if (KeyFormat == "HEX") {
        string HexKey;

        // Decode the Hex Encoded Key
        StringSource ss(Key.str(), true,
            new HexDecoder(
                new StringSink(HexKey)
            ) // HexDecoder
        ); // StringSource
        KeySize = HexKey.size();
    }
    else {
        cerr << "Unsupported key format. Please choose 'DER', 'Base64' or 'HEX'\n";
        exit(1);
    }
    
    return KeySize; // return key size (bytes)
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