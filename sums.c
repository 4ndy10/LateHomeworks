#include <cs50.h>
#include <stdio.h>

int main()
{
    int sum = 0;

    for(int i = 1; i <= 1000; i++)
    {
        sum += i;
    }
    printf("La suma final es de: %i\n", sum);
}
