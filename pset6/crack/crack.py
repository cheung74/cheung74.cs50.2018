import sys
import crypt

def main():
    if len(sys.argv) != 2:
        print("Usage: ./crack hash")
        sys.exit(1)

    hashs = sys.argv[1]
    salt = hashs[0:2]
    letters = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

    for fifth in letters:
        for fourth in letters:
            for third in letters:
                for second in letters:
                    for first in letters:
                        password = f"{first}{second}{third}{fourth}{fifth}".strip()

                        if crypt.crypt(password, salt) == hashs:
                            print(password.upper())
                            sys.exit(0)

if __name__ == "__main__":
    main()