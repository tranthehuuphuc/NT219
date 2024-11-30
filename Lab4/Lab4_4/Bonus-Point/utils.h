#include <iostream> 
#include <string>
#include <vector>
#include <sstream> 
#include <stdint.h>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef vector<uint8_t> bytes;


string hex(bytes &b)
{
    stringstream ss;
    ss << std::hex << std::setfill('0');
    
    for (const auto& byte : b) {
        ss << std::setw(2) << static_cast<int>(byte);
    }
    return ss.str();
}   

bytes decode_hex(string hexstr)
{
    vector<uint8_t> bytes_;
    for (size_t i = 0; i < hexstr.length(); i += 2) 
    {
        string byteString = hexstr.substr(i, 2);
        uint8_t b = static_cast<uint8_t>(stoul(byteString, nullptr, 16));
        bytes_.push_back(b);
    }
    return bytes_;
}
bytes concat(bytes vector1, bytes vector2)
{
    vector1.insert(vector1.end(), vector2.begin(), vector2.end());
    return vector1;
}
bytes int_to_bytes(long long num, int length) {
    bytes result;
    while (num > 0)
    {
        result.push_back(num % 256);
        num = num / 256;
    }
    if (result.size() < length)
    {
        vector<uint8_t> add(length - result.size(), 0);
        result = concat(result, add);
    }
    reverse(result.begin(), result.end());
    return result;
}
bytes slice(bytes data, int begin, int end)
{
    bytes result;
    for (int i = begin; i < end; i++)
    {
        result.push_back(data[i]);
    }
    return result;
}
class HASH
{
public:
    int BLOCKSIZE;
    bytes original_message;
    HASH(bytes message, int size)
    {
        BLOCKSIZE = size;
        original_message = message;
    }
    void _update(bytes message)
    {
        original_message = concat(original_message, message);
    }
    bytes _padding(bytes message)
    {
        int bit_length = message.size() * 8;
        message.push_back(0x80);
        while ((message.size() * 8 + BLOCKSIZE) % (BLOCKSIZE * 8))
        {
            message.push_back(0);
        }
        bytes add = int_to_bytes(bit_length, BLOCKSIZE / 8);
        message = concat(message, add);
        return message;
    }
    vector<bytes> _prasing(bytes padded_message)
    {
        vector<bytes> blocks;
        for (int i = 0; i < padded_message.size(); i += BLOCKSIZE)
        {
            blocks.push_back(slice(padded_message, i, i + BLOCKSIZE));
        }
        return blocks;
    }
};
