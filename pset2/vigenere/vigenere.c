#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    //if loop for the prompt value
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    //conver string of argv[1] to int key
    string key = argv[1];

    //test for each of char alalphabetical
    for(int n = 0; n < strlen(key); n++)
    {
        if (isalpha (key[n]) == false)
        {
        printf("Usage: ./caesar k\n");
        return 1;
        }
    }

    string x = get_string("plaintext:  ");

    printf("ciphertext: ");

    //for loop for ciphertext
    for (int i = 0, z = 0, n = strlen(x), y = strlen(key); i < n; i++)
    {
        //if loop for the uppercase letter
        if (x[i] >= 'A' && x[i] <= 'Z')
        {
            x[i] = (((x[i] - 'A') + toupper(key[(z % y)]) - 'A') % 26) + 'A';
            printf("%c", x[i]);
            z++;
        }
        //if loop for the lowercase letter
        else if(x[i] >= 'a' && x[i] <= 'z')
        {
            x[i] = (((x[i] - 'a') + toupper(key[(z % y)]) - 'A') % 26) + 'a';
            printf("%c", x[i]);
            z++;
        }
        //if the char is non alphbetic, print original char
        else
        {
            printf("%c", x[i]);
        }

    }
    printf("\n");
    return 0;
}