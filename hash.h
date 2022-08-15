#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>


#define Number 18278


int hash(const char *word)
{
    // Key is the same whether the first character is upper case or lower case
    unsigned int key = 0, First_Letter_Index = 0, Second_Letter_Index = 0, Third_Letter_Index = 0;

    // Calculate the length of the word that needs to be inserted in the hash table
    int Word_Lengh = strlen(word);

    if (Word_Lengh == 1)
    {
        if (65 <= word[0] && word[0] <= 90)
        {
            Third_Letter_Index = (word[0] - 65 + 1) % Number;
        }
        else if (97 <= word[0] && word[0] <= 122)
        {
            Third_Letter_Index = (word[0] - 97 + 1) % Number;
        }
    }
    if (Word_Lengh == 2)
    {
        if (65 <= word[0] && word[0] <= 90)
        {
            Second_Letter_Index = (word[0] - 65 + 1) % Number;
        }
        else if (97 <= word[0] && word[0] <= 122)
        {
            Second_Letter_Index = (word[0] - 97 + 1) % Number;
        }
        /********************************************************/
        if (65 <= word[1] && word[1] <= 90)
        {
            Third_Letter_Index = (word[1] - 65 + 1) % Number;
        }
        else if (97 <= word[1] && word[1] <= 122)
        {
            Third_Letter_Index = (word[1] - 97 + 1) % Number;
        }
    }
    if (Word_Lengh >= 3)
    {
        if (65 <= word[0] && word[0] <= 90)
        {
            First_Letter_Index = (word[0] - 65 + 1) % Number;
        }
        else if (97 <= word[0] && word[0] <= 122)
        {
            First_Letter_Index = (word[0] - 97 + 1) % Number;
        }
        /********************************************************/
        if (65 <= word[1] && word[1] <= 90)
        {
            Second_Letter_Index = (word[1] - 65 + 1) % Number;
        }
        else if (97 <= word[1] && word[1] <= 122)
        {
            Second_Letter_Index = (word[1] - 97 + 1) % Number;
        }
        /********************************************************/
        if (65 <= word[2] && word[2] <= 90)
        {
            Third_Letter_Index = (word[2] - 65 + 1) % Number;
        }
        else if (97 <= word[2] && word[2] <= 122)
        {
            Third_Letter_Index = (word[2] - 97 + 1) % Number;
        }
    }


    key = (First_Letter_Index * 26 * 26) + (Second_Letter_Index * 26) + (Third_Letter_Index * 1);
    return (key - 1);
}