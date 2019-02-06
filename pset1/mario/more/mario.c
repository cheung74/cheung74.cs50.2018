#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < (height - i - 1); j++)
        {
            printf(" ");
        }
        for (int k = 0; k < (i + 1); k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k < (i + 1); k++)
        {
            printf("#");
        }

        printf("\n");
    }
}