
// HASHES.cpp
// Created by Trần Thế Hữu Phúc

// C/C++ standard libraries
#include <chrono>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
using std::string;

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#endif

// Cryptopp library
#include <cryptopp/cryptlib.h>
#include "cryptopp/sha3.h"
#include "cryptopp/sha.h"
#include "cryptopp/shake.h"
#include "cryptopp/hex.h"
#include "cryptopp/files.h"

using CryptoPP::FileSink;
using namespace std;
using namespace CryptoPP;


unique_ptr<HashTransformation> selectHashFunction(const string &hashType) {
    if (hashType == "SHA_224")
        return make_unique<SHA224>();
    if (hashType == "SHA_256")
        return make_unique<SHA256>();
    if (hashType == "SHA_384")
        return make_unique<SHA384>();
    if (hashType == "SHA_512")
        return make_unique<SHA512>();
    if (hashType == "SHA3_224")
        return make_unique<SHA3_224>();
    if (hashType == "SHA3_256")
        return make_unique<SHA3_256>();
    if (hashType == "SHA3_384")
        return make_unique<SHA3_384>();
    if (hashType == "SHA3_512")
        return make_unique<SHA3_512>();
    if (hashType == "SHAKE128")
        return make_unique<SHAKE128>();
    if (hashType == "SHAKE256")
        return make_unique<SHAKE256>();
    return nullptr;
}

void hashes(const char *algo, const char *InputFile, const char *OutputFile, int ShakeLength) {
    string hashType(algo);
    string inputFile(InputFile);
    string outputFile(OutputFile);
    int shakeLength = ShakeLength / 8;

    // Select the hash function
    auto hash = selectHashFunction(hashType);
    if (!hash)
    {
        cerr << "Invalid hash type: " << hashType << endl;
        return;
    }

    // Read the input file
    string inputData;
    ifstream file(inputFile, ios::binary);
    if (!file) {
        cerr << "Error opening file: " << inputFile << std::endl;
        exit(1);
    }
    inputData = string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    // Calculate the hash
    string digest;
    hash->Update((const CryptoPP::byte *)inputData.data(), inputData.size());
    if (hashType == "SHAKE128" || hashType == "SHAKE256") {
        digest.resize(shakeLength);
        hash->TruncatedFinal((CryptoPP::byte *)&digest[0], shakeLength);
    }
    else {
        digest.resize(hash->DigestSize());
        hash->Final((CryptoPP::byte *)&digest[0]);
    }

    // Write the hash to the output file
    string encoded;
    StringSource(digest, true, new HexEncoder(new StringSink(encoded)));
    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Error opening output file: " << outputFile << std::endl;
        exit(1);
    }
    outFile << encoded << endl;
    outFile.close();
    
    // Print the hash
    // cout << "Digest: " << encoded << endl;
}

int main(int argc, char *argv[]) {
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

    if (argc != 4 && argc != 5) {
        std::cerr << "Usage: "
                  << argv[0] << " <hash_type> <input_file> <output_file> [<shake_length>]" << std::endl;
        std::cerr << "\tHash type: SHA_224, SHA_256, SHA_384, SHA_512, SHA3_224, SHA3_256, SHA3_384, SHA3_512, SHAKE128, SHAKE256" << std::endl;
        std::cerr << "\tInput file: Path of the plain text file" << std::endl;
        std::cerr << "\tOutput file: Path of the hashed text file" << std::endl;
        std::cerr << "\t[<shake_length>]: Output length for SHAKE128 or SHAKE256 (optional)" << std::endl;
        return 1;
    }

    int shakeLength = (argc == 5) ? std::stoi(argv[4]) : 256;

    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;

    start = std::chrono::high_resolution_clock::now();
    hashes(argv[1], argv[2], argv[3], shakeLength);
    end = std::chrono::high_resolution_clock::now();

    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
    cout << (double)(duration.count() / 1000.0);

    return 0;
}