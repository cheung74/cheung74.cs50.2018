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
    int key = atoi(argv[1]);

    string x = get_string("plaintext: ");
    
    printf("ciphertext: ");
    
    //for loop for ciphertext
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        //if loop for the uppercase letter
        if(x[i] >= 'A' && x[i] <= 'Z')
        {
            x[i] = (((x[i] - 'A') + key) % 26) + 'A';
            printf("%c", x[i]);
        }
        //if loop for the lowercase letter
        else if(x[i] >= 'a' && x[i] <= 'z')
        {
            x[i] = (((x[i] - 'a') + key) % 26) + 'a';
            printf("%c", x[i]);
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