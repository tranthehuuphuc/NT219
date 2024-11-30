#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <codecvt>
#include <locale>
#include <chrono>
#include <stdexcept>
#include <random>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#endif

#include "AES.h"

using namespace std;
using namespace std::chrono;

std::string vectorUint8ToString(const std::vector<uint8_t> &data)
{
    return std::string(data.begin(), data.end());
}

std::vector<uint8_t> stringToVectorUint8(const std::string &str)
{
    return std::vector<uint8_t>(str.begin(), str.end());
}

std::vector<uint8_t> readBinaryFile(const std::string &filePath)
{
    std::ifstream file(filePath, std::ios::binary);
    if (!file)
    {
        throw std::runtime_error("Could not open file: " + filePath);
    }

    // Determine the file size
    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Read the entire file into a vector<uint8_t>
    std::vector<uint8_t> buffer(fileSize);
    file.read(reinterpret_cast<char*>(buffer.data()), fileSize);

    if (!file)
    {
        throw std::runtime_error("Error reading file: " + filePath);
    }

    return buffer;
}

void writeBytesToFile(const std::string &filePath, const std::vector<uint8_t> &data)
{
    std::ofstream file(filePath, std::ios::binary);
    if (!file)
    {
        throw std::runtime_error("Could not open file for writing: " + filePath);
    }
    file.write(reinterpret_cast<const char *>(data.data()), data.size());
}

void KeyGeneration(int key_length, std::string KeyPath, std::string IVPath) {
    std::vector<uint8_t> key_bytes;
    if (key_length == 128) {
        key_bytes.resize(16);
    }
    else if (key_length == 192) {
        key_bytes.resize(24);
    }
    else if (key_length == 256) {
        key_bytes.resize(32);
    }
    else {
        throw std::invalid_argument("Invalid key length");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint8_t> distrib(0, 255);

    // Generate random key
    for (size_t i = 0; i < key_bytes.size(); i++)
    {
        key_bytes[i] = distrib(gen);
    }
    writeBytesToFile(KeyPath, key_bytes);

    // Generate random IV
    std::vector<uint8_t> iv_bytes(16);
    for (size_t i = 0; i < iv_bytes.size(); i++)
    {
        iv_bytes[i] = distrib(gen);
    }
    writeBytesToFile(IVPath, iv_bytes);
}

void Encryption(std::string KeyPath, std::string IVPath, std::string PlaintextPath, std::string CipherPath) {
    std::vector<uint8_t> key = readBinaryFile(KeyPath);
    std::vector<uint8_t> iv = readBinaryFile(IVPath);
    std::vector<uint8_t> plaintext = readBinaryFile(PlaintextPath);

    AES Encryptor(key, iv);
    std::vector<uint8_t> cipher = Encryptor.CBC_Encrypt(plaintext);

    writeBytesToFile(CipherPath, cipher);
}

void Decryption(std::string KeyPath, std::string IVPath, std::string CipherPath, std::string DecryptedPath) {
    std::vector<uint8_t> key = readBinaryFile(KeyPath);
    std::vector<uint8_t> iv = readBinaryFile(IVPath);
    std::vector<uint8_t> cipher = readBinaryFile(CipherPath);

    AES Decryptor(key, iv);
    std::vector<uint8_t> recovered = Decryptor.CBC_Decrypt(cipher);

    writeBytesToFile(DecryptedPath, recovered);
}

int main(int argc, char* argv[]) {
    // Set UTF-8 Encoding
	#ifdef __linux__
		std::locale::global(std::locale("C.UTF-8"));
	#elif _WIN32
        // Set console code page to UTF-8 on Windows
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
	#endif

    high_resolution_clock::time_point start, end;

    if (argc != 5 && argc != 6) {
        std::cerr << "Usage: " << argv[0] << " <command> [options]\n"
        << "Command:\n" 
        << "\t keygen <Key_Length> <Key_File> <IV_File>\n"
        << "\t encrypt <Key_File> <IV_File> <Plaintext_File> <Ciphertext_File>\n"
        << "\t decrypt <Key_File> <IV_File> <Ciphertext_File> <Recovered_File>\n";
        return 1;
    }

    std::string command = argv[1];
    if (command == "keygen") {
        if (argc != 5) {
            std::cerr << "Usage: " << argv[0] << " keygen <Key_Length> <Key_File> <IV_File>\n";
            return 1;
        }

        int key_length = std::stoi(argv[2]);
        std::string key_file = argv[3];
        std::string iv_file = argv[4];

        start = std::chrono::high_resolution_clock::now();
        KeyGeneration(key_length, key_file, iv_file);
        end = std::chrono::high_resolution_clock::now();

        std::cout << "Key and IV generated successfully.\n";
    }
    else if (command == "encrypt") {
        if (argc != 6) {
            std::cerr << "Usage: " << argv[0] << " encrypt <Key_File> <IV_File> <Plaintext_File> <Cipher_File>\n";
            return 1;
        }

        std::string key_file = argv[2];
        std::string iv_file = argv[3];
        std::string plaintext_file = argv[4];
        std::string cipher_file = argv[5];

        start = std::chrono::high_resolution_clock::now();
        Encryption(key_file, iv_file, plaintext_file, cipher_file);
        end = std::chrono::high_resolution_clock::now();

        std::cout << "Encryption completed successfully.\n";
    }
    else if (command == "decrypt") {
        if (argc != 6) {
            std::cerr << "Usage: " << argv[0] << " decrypt <Key_File> <IV_File> <Cipher_File> <Decrypted_File>\n";
            return 1;
        }

        std::string key_file = argv[2];
        std::string iv_file = argv[3];
        std::string cipher_file = argv[4];
        std::string decrypted_file = argv[5];

        start = std::chrono::high_resolution_clock::now();
        Decryption(key_file, iv_file, cipher_file, decrypted_file);
        end = std::chrono::high_resolution_clock::now();

        std::cout << "Decryption completed successfully.\n";
    }
    else {
        std::cerr << "Invalid command.\n";
        return 1;
    }

    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // cout << (double)(duration.count() / 1000.0) << endl;

    return 0;
}