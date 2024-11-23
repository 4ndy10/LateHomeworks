#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int times;

    // Ask the user for the number of times to print "Meow"
    do
    {
        times = get_int("Enter the number of times you want to print 'Meow': ");

        // If the number is non-positive, print "Meow" once
        if (times <= 0)
        {
            printf("Meow\n");
        }

    } while (times <= 0);  // Continue asking until the number is positive

    // Print "Meow" the specified number of times
    for (int i = 1; i <= times; i++)
    {
        printf("%i.- Meow\n", i);
    }

    return 0;
}
