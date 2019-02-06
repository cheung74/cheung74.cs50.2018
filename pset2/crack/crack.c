#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    //if loop for confirming the input value is valid
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    //the max size of crpyt key is 56bit, add 1bit for \0
    int key_count = 57;

    //define the key range and get the hash from argv[1]
    string letter = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string hash = argv[1];

    //deine the salt, following requirment of considering first two char
    char salt[3];

    //copy the memory of salt from hash
    memcpy(salt, hash, 2);

    //define the end point of salt
    salt[2] = '\0';

    //define the array of password, consider 5 chars + \0
    char password[6];

    //define the end value of the password
    password[5] = '\0';

    //nested for loop to find the password
    //each level to find the password per char
    for (int m = 0; m < key_count; m++)
    {
        //for loop for the first + second + third + fourth + fifh chars
        for (int l = 0; l < key_count; l++)
        {
            //for loop for the first + second + third + fourth chars
            for (int k = 0; k < key_count; k++)
            {
                    //for loop for the first + second + third chars
                for (int j = 0; j < key_count; j++)
                {
                        //for loop for the first + second chars
                    for (int i = 1; i < key_count; i++)
                    {
                    //for loop for the first char
                    password[0] = letter[i];
                    password[1] = letter[j];
                    password[2] = letter[k];
                    password[3] = letter[l];
                    password[4] = letter[m];

                    if(strcmp(crypt(password, salt), hash) == 0)
                        {
                            // checking the password and the hash
                        printf("%s", letter);
                        return 0;
                        }
                    }
                }
            }
        }
    }
}
