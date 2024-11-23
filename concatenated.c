#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string word1 = get_string("Write the first word: ");
    string word2 = get_string("Write the second word: ");
    printf("%s %s!!!!\n", word1, word2);
}
