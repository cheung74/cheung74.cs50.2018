from cs50 import get_int
from math import floor


def main():
    #define variables
    x1 = 0
    x2 = 0
    num_digits = 0
    x1sum = 0
    x2sum = 0
    card_number = get_int("Number: ")
    #while loop for calucating the validity of the number
    while card_number > 0:
        x2 = x1
        x1 = card_number % 10

        if num_digits % 2 == 0:
            x2sum += x1
        else:
            multiple = 2 * x1
            x2sum += (multiple // 10) + (multiple % 10)

        card_number //= 10
        num_digits += 1

    is_valid = (x1sum + x2sum) % 10 == 0
    first_two_digits = (x1 * 10) + x2
    #check for the card company
    if x1 == 4 and num_digits >= 13 and num_digits <= 16 and is_valid:
        print("VISA")
    elif first_two_digits >= 51 and first_two_digits <= 55 and num_digits == 16 and is_valid:
        print("MASTERCARD")
    elif first_two_digits == 34 or first_two_digits == 37 and num_digits == 15 and is_valid:
        print("AMEX")
    else:
        print("INVALID")




if __name__ == "__main__":

    main()