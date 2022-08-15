#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "hash.h"


#define Number 18278


typedef struct node
{
    char word[46];
    struct node *next;
}
node;


node *table[Number];


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


int main(void)
{
    printf("hello, world\n");
    char *list[16];
    list[0] = "I";
    list[1] = "am";
    list[2] = "Mohamed";
    list[3] = "Alkobrosly";

    list[4] = "I";
    list[5] = "will";
    list[6] = "describe";
    list[7] = "how";
    list[8] = "to";
    list[9] = "aplly";
    list[10] = "hash";
    list[11] = "function";
    list[12] = "and";
    list[13] = "hash";
    list[14] = "table";
    list[15] = "algorithm";

    for (int i = 0; i <16; i++)
    {
        hash(list[i]);
        insert(list[i]);
    }

    bool query_result = check("Mohamed");
    if (query_result == true)
    {
        printf("Query result exists for value: Mohamed\n");
    }
    else
    {
        printf("Query result does not exist for value: Mohamed\n");
    }

    delete("Mohamed");

    query_result = check("Mohamed");
    if (query_result == true)
    {
        printf("Query result exists for value: Mohamed\n");
    }
    else
    {
        printf("Query result does not exist for value: Mohamed\n");
    }

    update("Alkobrosly", "Alkobrosli");

    query_result = check("Alkobrosli");
    if (query_result == true)
    {
        printf("Query result exists for value: Alkobrosli\n");
    }
    else
    {
        printf("Query result does not exist for value: Alkobrosli\n");
    }

    unload();
}