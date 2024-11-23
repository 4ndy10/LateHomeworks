#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number1 = get_int("Enter the number to display it's multiplication table: ");
    int number2 = get_int("Enter the limit number of the multiplication table: ");

    int table[number2];
    for(int i = 1; i <= number2; i++)
    {
        table[i] = number1 * (i);
    }

    printf("Multiplication table for %i: \n", number1);
    for(int i = 1; i <= number2; i++)
    {
        printf("%i x %i = %i\n", number1, i, table[i]);
    }

}
