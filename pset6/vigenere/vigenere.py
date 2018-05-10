

# Code written by: Mohammad Alsalkini


from cs50 import get_string
from cs50 import get_int
import sys

# vigenere's cipher


def cipher_vigenere(plaintext, key):
    for character in plaintext:
        if character.isalpha():
            # checking if the input is an alphapet
            if character.isupper():
                return chr(((ord(character) - 65 + key) % 26) + 65)
            # checking if the input is capital letter
            else:
                return chr(((ord(character) - 97 + key) % 26) + 97)
        # The input is not an alphapet
        else:
            return character


def main():
    if len(sys.argv) != 2:
        print("Usage: ./vigenere k")
        exit(1)

    key = sys.argv[1]
    keylength = len(sys.argv[1])

    for character in key:
        # checking if the salt an alphapet
        if not character.isalpha():
            print("Usage: ./vigenere k")
            exit(1)

    plaintext = get_string("plaintext: ")
    print("ciphertext: ", end="")
    key_counter = 0
    cipher_text = []

    # applying cipher_vigenere
    for character in plaintext:
        shift = 0
        if key_counter == keylength:
            key_counter = 0
        shift = ord(key[key_counter].lower()) - 97
        cipher_text.append(cipher_vigenere(character, shift))
        key_counter += 1
    print("".join(cipher_text))


if __name__ == "__main__":
    main()