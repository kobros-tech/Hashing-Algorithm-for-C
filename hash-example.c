#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "hash-operations.c"


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