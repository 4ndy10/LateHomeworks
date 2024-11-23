#include <cs50.h>
#include <stdio.h>

int main()
{
    printf("Even numbers between 1 and 100:\n");
    for(int i = 0; i <= 1000; i += 2)
    {
        printf("%d\n", i);
    }
}
