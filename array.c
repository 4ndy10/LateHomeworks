#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number = get_int("Enter a number: ");

    int table[1];
    for(int i = 1; i <= 10; i++)
    {
        table[i] = number * (i);
    }

    printf("Multiplication table for %i: \n", number);
    for(int i = 1; i <= 10; i++)
    {
        printf("%i x %i = %i\n", number, i, table[i]);
    }

}
