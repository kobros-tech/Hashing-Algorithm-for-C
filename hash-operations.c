#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "hash.h"


bool insert(char *value)
{
    // Make a new node and copy the word inside it
    node *NewNode = malloc(sizeof(node));
    if (NewNode == NULL)
    {
        return false;
    }
    strcpy(NewNode->word, value);
    NewNode->next = NULL;

    // Calculate the hash key
    // Key is the same whether the first character is upper case or lower case
    unsigned int Key;
    Key = hash(value);

    // Check if chain[key] is empty
    if (table[Key] == NULL)
    {
        table[Key] = NewNode;
    }
    // Collision
    else
    {
        // Those two lines must be in order, otherwise you lose your chain
        NewNode->next = table[Key];
        table[Key] = NewNode;
    }
    return true;
}


bool check(const char *word)
{
    unsigned int Key;
    Key = hash(word);

    node *temp = table[Key];


    // Calculate the length of the word that needs to be searched in the hash table
    while (temp)
    {
        if (strcasecmp(word, temp->word) == 0)
        {
            // The word matches the data
            return true;
        }
        temp = temp->next;
    }
    // Otherwise
    return false;
}


bool update(const char *word, const char *new_word)
{
    unsigned int Key;
    Key = hash(word);

    node *temp = table[Key];


    // Calculate the length of the word that needs to be searched in the hash table
    while (temp)
    {
        if (strcasecmp(word, temp->word) == 0)
        {
            // The word matches the data
            strcpy(temp->word, new_word);
            return true;
        }
        temp = temp->next;
    }
    // Otherwise
    return false;
}


bool delete(const char *word)
{
    unsigned int Key;
    Key = hash(word);

    node *temp = table[Key];
    node *pretemp;


    // Calculate the length of the word that needs to be searched in the hash table
    while (temp)
    {
        pretemp = temp;
        if (strcasecmp(word, temp->word) == 0)
        {
            // The word matches the data
            if (temp->next != NULL)
            {
                temp = temp->next;
                pretemp->next = temp;
                // strcpy(temp->word, "");
                temp = NULL;
                return true;
            }
            else
            {
                // strcpy(temp->word, "");
                temp = NULL;
                return true;
            }
        }
        else
        {
            temp = temp->next;
        }
    }
    // Otherwise
    return false;
}


bool unload(void)
{
    node *FreeNode;
    for (int i = 0; i < Number; i++)
    {
        // Free list, by using a while loop and a temporary variable to point
        // to the next node before freeing the current one
        while (table[i] != NULL)
        {
            FreeNode = table[i]->next;
            free(table[i]);
            table[i] = FreeNode;
        }

    }
    return true;
}