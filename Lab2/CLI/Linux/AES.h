#ifndef AES_CBC_H
#define AES_CBC_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdint>
#include <algorithm>
#include <stdexcept>

class AES
{
protected:
    std::vector<std::vector<uint8_t>> round_keys;
    std::vector<uint8_t> key;
    std::vector<uint8_t> iv;
    int key_length;
    int num_rounds;

    static const std::vector<uint8_t> S_BOX;
    static const std::vector<uint8_t> INV_S_BOX;
    static const std::vector<std::vector<uint8_t>> RCON;

    std::vector<uint8_t> PKCS7_Padding(const std::vector<uint8_t> &data) {
        size_t padding_length = 16 - (data.size() % 16);
        std::vector<uint8_t> padded_data = data;
        for (size_t i = 0; i < padding_length; i++) {
            padded_data.push_back(static_cast<uint8_t>(padding_length));
        }
        return padded_data;
    }

    std::vector<uint8_t> PKCS7_Unpadding(const std::vector<uint8_t> &data) {
        if (data.empty()) {
            return data;
        }

        size_t padding_length = data.back();
        if (padding_length > data.size()) {
            return data;
        }

        for (size_t i = 0; i < padding_length; i++) {
            if (data[data.size() - 1 - i] != static_cast<uint8_t>(padding_length)) {
                return data;
            }
        }

        return std::vector<uint8_t>(data.begin(), data.end() - padding_length);
    }

    std::vector<std::vector<uint8_t>> key_expansion(const std::vector<uint8_t> &key) {
        this->key = key;
        int key_words = key_length / 32;
        int num_round_keys = (key_words + 6 + 1) * 4;

        std::vector<std::vector<uint8_t>> round_keys;
        for (int i = 0; i < key_words; i++) {
            round_keys.push_back({key[4 * i], key[4 * i + 1], key[4 * i + 2], key[4 * i + 3]});
        }

        for (int i = key_words; i < num_round_keys; i++) {
            std::vector<uint8_t> temp = round_keys[i - 1];
            if (i % key_words == 0) {
                temp = rot_word(temp);
                temp = sub_word(temp);
                for (int j = 0; j < 4; j++) {
                    temp[j] ^= RCON[(i / key_words) - 1][j];
                }
            } else if (key_length == 256 && i % key_words == 4) {
                temp = sub_word(temp);
            }
            std::vector<uint8_t> new_round_key(4);
            for (int j = 0; j < 4; j++) {
                new_round_key[j] = round_keys[i - key_words][j] ^ temp[j];
            }
            round_keys.push_back(new_round_key);
        }
        return round_keys;
    }

    std::vector<uint8_t> sub_word(std::vector<uint8_t> &word) {
        for (int i = 0; i < 4; i++) {
            word[i] = S_BOX[word[i]];
        }
        return word;
    }

    std::vector<uint8_t> rot_word(std::vector<uint8_t> &word) {
        uint8_t temp = word[0];
        for (int i = 0; i < 3; i++) {
            word[i] = word[i + 1];
        }
        word[3] = temp;
        return word;
    }

    std::vector<std::vector<uint8_t>> sub_bytes(std::vector<std::vector<uint8_t>> state) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                state[i][j] = S_BOX[state[i][j]];
            }
        }
        return state;
    }

    std::vector<std::vector<uint8_t>> shift_rows(std::vector<std::vector<uint8_t>> state) {
        for (int i = 1; i < 4; i++) {
            std::vector<uint8_t> temp(4);
            for (int j = 0; j < 4; j++) {
                temp[j] = state[i][(j + i) % 4];
            }
            for (int j = 0; j < 4; j++) {
                state[i][j] = temp[j];
            }
        }
        return state;
    }

    std::vector<std::vector<uint8_t>> mix_columns(std::vector<std::vector<uint8_t>> state) {
        std::vector<uint8_t> s = {0x02, 0x03, 0x01, 0x01};

        for (int i = 0; i < 4; i++) {
            std::vector<uint8_t> column(4);

            for (int j = 0; j < 4; j++) {
                column[j] = state[j][i];
            }

            state[0][i] = (uint8_t)(mul(s[0], column[0]) ^ mul(s[1], column[1]) ^ column[2] ^ column[3]);
            state[1][i] = (uint8_t)(column[0] ^ mul(s[0], column[1]) ^ mul(s[1], column[2]) ^ column[3]);
            state[2][i] = (uint8_t)(column[0] ^ column[1] ^ mul(s[0], column[2]) ^ mul(s[1], column[3]));
            state[3][i] = (uint8_t)(mul(s[1], column[0]) ^ column[1] ^ column[2] ^ mul(s[0], column[3]));
        }
        return state;
    }

    std::vector<std::vector<uint8_t>> inv_mix_columns(std::vector<std::vector<uint8_t>> state) {
        std::vector<std::vector<uint8_t>> result(4, std::vector<uint8_t>(4));

        for (int i = 0; i < 4; i++) {
            result[0][i] = mul(0x0e, state[0][i]) ^ mul(0x0b, state[1][i]) ^ mul(0x0d, state[2][i]) ^ mul(0x09, state[3][i]);
            result[1][i] = mul(0x09, state[0][i]) ^ mul(0x0e, state[1][i]) ^ mul(0x0b, state[2][i]) ^ mul(0x0d, state[3][i]);
            result[2][i] = mul(0x0d, state[0][i]) ^ mul(0x09, state[1][i]) ^ mul(0x0e, state[2][i]) ^ mul(0x0b, state[3][i]);
            result[3][i] = mul(0x0b, state[0][i]) ^ mul(0x0d, state[1][i]) ^ mul(0x09, state[2][i]) ^ mul(0x0e, state[3][i]);
        }

        return result;
    }

    std::vector<std::vector<uint8_t>> add_round_key(std::vector<std::vector<uint8_t>> state, int round_number) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                state[j][i] ^= round_keys[round_number * 4 + i][j];
            }
        }
        return state;
    }

    std::vector<std::vector<uint8_t>> inv_sub_bytes(std::vector<std::vector<uint8_t>> state) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                state[i][j] = INV_S_BOX[state[i][j]];
            }
        }
        return state;
    }

    std::vector<std::vector<uint8_t>> inv_shift_rows(std::vector<std::vector<uint8_t>> state) {
        for (int i = 1; i < 4; i++) {
            std::vector<uint8_t> temp(4);
            for (int j = 0; j < 4; j++) {
                temp[j] = state[i][(j - i + 4) % 4];
            }
            for (int j = 0; j < 4; j++) {
                state[i][j] = temp[j];
            }
        }
        return state;
    }

    uint8_t mul(uint8_t a, uint8_t b) {
        uint8_t result = 0;
        while (a && b) {
            if (b & 1) {
                result ^= a;
            }
            if (a & 0x80) {
                a = (a << 1) ^ 0x1b;
            } else {
                a <<= 1;
            }
            b >>= 1;
        }
        return result;
    }

    std::vector<std::vector<uint8_t>> encrypt_block(std::vector<std::vector<uint8_t>> state) {
        state = add_round_key(state, 0);
        for (int round = 1; round < num_rounds; round++) {
            state = sub_bytes(state);
            state = shift_rows(state);
            state = mix_columns(state);
            state = add_round_key(state, round);
        }
        state = sub_bytes(state);
        state = shift_rows(state);
        state = add_round_key(state, num_rounds);
        return state;
    }

    std::vector<std::vector<uint8_t>> decrypt_block(std::vector<std::vector<uint8_t>> state) {
        state = add_round_key(state, num_rounds);
        for (int round = num_rounds - 1; round > 0; round--) {
            state = inv_shift_rows(state);
            state = inv_sub_bytes(state);
            state = add_round_key(state, round);
            state = inv_mix_columns(state);
        }
        state = inv_shift_rows(state);
        state = inv_sub_bytes(state);
        state = add_round_key(state, 0);
        return state;
    }

public:
    AES(const std::vector<uint8_t> &key, const std::vector<uint8_t> &iv) {
        if (key.size() == 16) {
            key_length = 128;
            num_rounds = 10;
        } else if (key.size() == 24) {
            key_length = 192;
            num_rounds = 12;
        } else if (key.size() == 32) {
            key_length = 256;
            num_rounds = 14;
        } else {
            throw std::invalid_argument("Key length must be 128, 192, or 256 bits.");
        }
        if (iv.size() != 16) {
            throw std::invalid_argument("IV length must be 128 bits.");
        }
        this->iv = iv;
        round_keys = key_expansion(key);
    }

    std::vector<uint8_t> CBC_Encrypt(const std::vector<uint8_t> &plaintext) {
        std::vector<uint8_t> padded_plaintext = PKCS7_Padding(plaintext);
        std::vector<uint8_t> ciphertext;
        std::vector<uint8_t> previous_block = iv;

        for (size_t i = 0; i < padded_plaintext.size(); i += 16) {
            std::vector<std::vector<uint8_t>> block(4, std::vector<uint8_t>(4));
            for (int j = 0; j < 16; j++) {
                block[j % 4][j / 4] = padded_plaintext[i + j] ^ previous_block[j];
            }

            block = encrypt_block(block);

            for (int j = 0; j < 16; j++) {
                ciphertext.push_back(block[j % 4][j / 4]);
                previous_block[j] = block[j % 4][j / 4];
            }
        }

        return ciphertext;
    }

    std::vector<uint8_t> CBC_Decrypt(const std::vector<uint8_t> &ciphertext) {
        std::vector<uint8_t> padded_plaintext;
        std::vector<uint8_t> previous_block = iv;

        for (size_t i = 0; i < ciphertext.size(); i += 16) {
            std::vector<std::vector<uint8_t>> block(4, std::vector<uint8_t>(4));
            std::vector<uint8_t> current_block(16);
            for (int j = 0; j < 16; j++) {
                block[j % 4][j / 4] = ciphertext[i + j];
                current_block[j] = ciphertext[i + j];
            }

            block = decrypt_block(block);

            for (int j = 0; j < 16; j++) {
                padded_plaintext.push_back(block[j % 4][j / 4] ^ previous_block[j]);
            }
            previous_block = current_block;
        }

        return PKCS7_Unpadding(padded_plaintext);
    }
};

const std::vector<uint8_t> AES::S_BOX = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};

const std::vector<uint8_t> AES::INV_S_BOX = {
        0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
        0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
        0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
        0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
        0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
        0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
        0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
        0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
        0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
        0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
        0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
        0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
        0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
        0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
        0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
        0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};

const std::vector<std::vector<uint8_t>> AES::RCON = {
    {0x01, 0x00, 0x00, 0x00}, {0x02, 0x00, 0x00, 0x00},
    {0x04, 0x00, 0x00, 0x00}, {0x08, 0x00, 0x00, 0x00},
    {0x10, 0x00, 0x00, 0x00}, {0x20, 0x00, 0x00, 0x00},
    {0x40, 0x00, 0x00, 0x00}, {0x80, 0x00, 0x00, 0x00},
    {0x1b, 0x00, 0x00, 0x00}, {0x36, 0x00, 0x00, 0x00}
};

#endif
