#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int a = 0,num_coin = 0;
    float amount = 0;

    do
    {
        amount = get_float("Change owed: ");
    }
    while (amount < 0);

        a = round(amount*100);

        int quarter = a / 25;
        int dime = (a % 25) / 10;
        int nickel = ((a % 25) % 10) / 5;
        int pennie = ((a % 25) % 10) % 5;
        num_coin = quarter + dime + nickel + pennie;

    printf("%d\n",num_coin);
}