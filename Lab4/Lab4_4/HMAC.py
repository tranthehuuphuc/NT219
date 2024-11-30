import hashlib
import hmac

def generate_hmac_sha1(key, message):
    return hmac.new(key, message, hashlib.sha1).hexdigest()

def generate_hmac_sha256(key, message):
    return hmac.new(key, message, hashlib.sha256).hexdigest()


def generate_hmac_sha512(key, message):
    return hmac.new(key, message, hashlib.sha512).hexdigest()

# Ví dụ sử dụng
key = b'tranthehuuphuc'
message = b'mat-ma-hoc-vui-ghe'
hmac_digest = generate_hmac_sha1(key, message)
print(f'HMAC-SHA1: {hmac_digest}')
hmac_digest = generate_hmac_sha256(key, message)
print(f'HMAC-SHA256: {hmac_digest}')
hmac_digest = generate_hmac_sha512(key, message)
print(f'HMAC-SHA512: {hmac_digest}')
