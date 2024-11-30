#include "sha256.h"

//use CryptoPP for testing implementation only
#include "cryptopp/cryptlib.h"
#include "cryptopp/sha.h"
#include "cryptopp/hex.h"
#include "cryptopp/files.h"
bytes urandom(int n)
{
    bytes arr(16);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 256;
    }
    return arr;
}
bytes str_to_bytes(string s)
{
    vector<uint8_t> bytes(s.begin(), s.end());
    return bytes;
}

string bytes_to_str(bytes b)
{
    return string(b.begin(), b.end());
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        std::cerr << "Usage: " << argv[0] << " <original data> <padding data> <signature in SHA256> <key length>\n";
        return -1;
    }

    std::string original = argv[1];
    std::string appended = argv[2];
    std::string signature = argv[3];
    int key_length = std::stoi(argv[4]);

    if (signature.length() != 64)
    {
        std::cerr << "Make sure you have a correct SHA256 signature!!!\n";
        return -1;
    }

    SHA256 hash;
    // convert data to bytes
    bytes original_bytes = str_to_bytes(original);
    bytes appended_bytes = str_to_bytes(appended);
    // attack
    std::pair<bytes, std::string> result = hash.attack(key_length, original_bytes, appended_bytes, signature);
    bytes new_data = result.first;
    std::string new_sig = result.second;
    std::cout << "New data: " << hex(new_data) << std::endl;
    std::cout << "Predicted signature: " << new_sig << std::endl;

    return 0;
}
