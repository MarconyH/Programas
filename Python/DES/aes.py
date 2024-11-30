from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.padding import PKCS7
import os

# Função para criptografar usando AES
def encrypt_aes(key, iv, plaintext):
    cipher = Cipher(algorithms.AES(key), modes.CBC(iv))
    padder = PKCS7(algorithms.AES.block_size).padder()
    padded_data = padder.update(plaintext.encode()) + padder.finalize()
    encryptor = cipher.encryptor()
    return encryptor.update(padded_data) + encryptor.finalize()

# Função para descriptografar usando AES
def decrypt_aes(key, iv, ciphertext):
    cipher = Cipher(algorithms.AES(key), modes.CBC(iv))
    decryptor = cipher.decryptor()
    decrypted_data = decryptor.update(ciphertext) + decryptor.finalize()
    unpadder = PKCS7(algorithms.AES.block_size).unpadder()
    return unpadder.update(decrypted_data) + unpadder.finalize()

# Teste do programa
if __name__ == "__main__":
    key = os.urandom(32)  # Gera uma chave de 32 bytes para AES
    iv = os.urandom(16)   # Gera um vetor de inicialização (IV)

    plaintext = "Mensagem Super Ultra Mega Secreta"  # Texto para criptografar
    print("Texto original:", plaintext)

    encrypted = encrypt_aes(key, iv, plaintext)
    print("Texto criptografado (hex):", encrypted.hex())

    decrypted = decrypt_aes(key, iv, encrypted)
    print("Texto descriptografado:", decrypted.decode())
