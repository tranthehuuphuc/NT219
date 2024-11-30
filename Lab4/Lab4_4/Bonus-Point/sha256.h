#include "utils.h"
#include <utility>
#include <assert.h>

typedef long long ll;
class CONST
{
public:
    ll H0 = 0x6a09e667;
    ll H1 = 0xbb67ae85;
    ll H2 = 0x3c6ef372;
    ll H3 = 0xa54ff53a;
    ll H4 = 0x510e527f;
    ll H5 = 0x9b05688c;
    ll H6 = 0x1f83d9ab;
    ll H7 = 0x5be0cd19;
    vector<ll> K = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
    int WORD_SIZE = 32;
    CONST(){}
    ll ROTR(ll x, int shift)
    {
        ll res = (x >> shift) | (x << (WORD_SIZE - shift));
        return res & 0xffffffff;
    }
    ll Ch(ll x, ll y, ll z)
    {
        ll res = (x & y) ^ (~x & z);
        return res & 0xffffffff;
    }
    ll Maj(ll x, ll y, ll z)
    {
        ll res = (x & y) ^ (x & z) ^ (y & z);
        return res & 0xffffffff;
    }
    ll sigma0(ll x)
    {
        ll res = ROTR(x, 7) ^ ROTR(x, 18) ^ (x >> 3);
        return res & 0xffffffff;
    }
    ll sigma1(ll x)
    {
        ll res = ROTR(x, 17) ^ ROTR(x, 19) ^ (x >> 10);
        return res & 0xffffffff;
    }
    ll SIGMA0(ll x)
    {
        ll res = ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22);
        return res & 0xffffffff;
    }
    ll SIGMA1(ll x)
    {
        ll res = ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25);
        return res & 0xffffffff;
    }
};
ll bytes_to_int(bytes b)
{
    ll res = 0;
    for (int i = 0; i < b.size(); i++)
    {
        res = 256*res + (int)b[i];
    }
    return res;
}

class SHA256 : public HASH
{
public:
    bytes __digest;
    SHA256(bytes message = {}) : HASH(message, 64)
    {
        __digest = __hashing();
    }
    void update(bytes message = {})
    {
        _update(message);
        __digest = __hashing();
    }
    bytes digest()
    {
        return __digest;
    }
    string hexdigest()
    {
        return hex(__digest);
    }
    pair<bytes, string> attack(int secret_length, bytes original_data, bytes appended_data, string signature)
    {
        bytes decoded_signature = decode_hex(signature);
        bytes null(secret_length, 0);
        bytes old_padded = _padding(concat(null, original_data));
        bytes old_padded_sliced = slice(old_padded, secret_length + original_data.size(), old_padded.size());
        bytes last_blocks = _padding(concat(concat(concat(null, original_data), old_padded_sliced),appended_data));
        last_blocks = slice(last_blocks, old_padded.size(), last_blocks.size());
        vector<ll> init_block;
        for (int i = 0; i < decoded_signature.size(); i += 4)
        {
            init_block.push_back(bytes_to_int(slice(decoded_signature, i, i + 4)));
        }
        bytes new_digest = __hashing(init_block, last_blocks);
        bytes new_data = concat(concat(original_data, slice(old_padded, secret_length + original_data.size(), old_padded.size())),appended_data);
        return make_pair(new_data, hex(new_digest));
    }
    bytes __hashing(vector<ll> init_block = {}, bytes last_blocks = {})
    {
        CONST _c;
        vector<bytes> blocks;
        bytes padded_message;
        ll h0, h1, h2, h3, h4, h5, h6, h7;

        if (!init_block.empty() && !last_blocks.empty())
        {
            blocks = _prasing(last_blocks);
            h0 = init_block[0];
            h1 = init_block[1];
            h2 = init_block[2];
            h3 = init_block[3];
            h4 = init_block[4];
            h5 = init_block[5];
            h6 = init_block[6];
            h7 = init_block[7];
        }
        else
        {
            padded_message = _padding(original_message);
            blocks = _prasing(padded_message);
            

            h0 = _c.H0;
            h1 = _c.H1;
            h2 = _c.H2;
            h3 = _c.H3;
            h4 = _c.H4;
            h5 = _c.H5;
            h6 = _c.H6;
            h7 = _c.H7;
        }
        for(auto message_block : blocks)
        {
            vector<bytes> W;
            for (int t = 0; t < 64; t++)
            {
                if(t <=15)
                {
                    W.push_back(slice(message_block, 4 * t, 4 * (t + 1)));
                }
                else
                {
                    ll term1 = _c.sigma1(bytes_to_int(W[t - 2]));
                    ll term2 = bytes_to_int(W[t - 7]);
                    ll term3 = _c.sigma0(bytes_to_int(W[t - 15]));
                    ll term4 = bytes_to_int(W[t - 16]);
                    bytes schedule = int_to_bytes((term1 + term2 + term3 + term4) & 0xffffffff, 4);
                    W.push_back(schedule);
                }
            } 
            ll a = h0;
            ll b = h1;
            ll c = h2;
            ll d = h3;
            ll e = h4;
            ll f = h5;
            ll g = h6;
            ll h = h7;
            for (int t = 0; t < 64; t++)
            {
                ll T1 = h + _c.SIGMA1(e) + _c.Ch(e, f, g) + _c.K[t] + bytes_to_int(W[t]);
                ll T2 = _c.SIGMA0(a) + _c.Maj(a, b, c);
                h = g;
                g = f;
                f = e;
                e = (d + T1) & 0xffffffff;
                d = c;
                c = b;
                b = a;
                a = (T1 + T2) & 0xffffffff;
            }
            h0 = (h0 + a) & 0xffffffff;
            h1 = (h1 + b) & 0xffffffff;
            h2 = (h2 + c) & 0xffffffff;
            h3 = (h3 + d) & 0xffffffff;
            h4 = (h4 + e) & 0xffffffff;
            h5 = (h5 + f) & 0xffffffff;
            h6 = (h6 + g) & 0xffffffff;
            h7 = (h7 + h) & 0xffffffff;

        }
        bytes res;
        res = concat(int_to_bytes(h0, 4), int_to_bytes(h1, 4));
        res = concat(res, int_to_bytes(h2, 4));
        res = concat(res, int_to_bytes(h3, 4));
        res = concat(res, int_to_bytes(h4, 4));
        res = concat(res, int_to_bytes(h5, 4));
        res = concat(res, int_to_bytes(h6, 4));
        res = concat(res, int_to_bytes(h7, 4));
        return res;
    }
};

