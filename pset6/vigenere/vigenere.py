import cs50
import sys

# Implements a Caesar cipher.
def main():

    # Gets key as int; validates
    cipher = sys.argv[1]

    if not cipher.isalpha or not len(sys.argv) == 2:
        exit(1)

    # Gets plaintext
    print("plaintext: ", end="")
    ptext = cs50.get_string()

    print("ciphertext: ", end="")

    # Counter for cipher
    n = 0

    # Enciphers while preserving case, prints
    for c in ptext:

        key = get_key(cipher, n)

        # Character is uppercase
        if c.isupper():
            upper = (((ord(c) - ord('A')) + key) % 26) + ord('A')
            print(chr(upper), end="")
            n += 1

        # Character is lowercase
        elif c.islower():
            lower = (((ord(c) - ord('a')) + key) % 26) + ord('a')
            print(chr(lower), end="")
            n += 1

        elif not c.isalpha():
            print("{}".format(c), end="")

    # Prints newline
    print()

# Gets key
def get_key(cipher, counter):
    pos = counter % len(cipher)

    if cipher[pos].isupper():
        return ord(cipher[pos]) - 65

    else:
        return ord(cipher[pos]) - 97

if __name__ == "__main__":
    main()