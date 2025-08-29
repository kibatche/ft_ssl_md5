#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *change_newline(char *message)
{
    unsigned int i = -1;
    unsigned int j = 0;
    unsigned int len = 0;
    char *str = NULL;
    
    while (++i < strlen(message))
    {
        if (message[i] == '\n' || message[i] == '\r')//yeah...
            len++;
    }
    len += i;
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
    {
        free(message);
    }
    i = -1;
    while (++i < strlen(message))
    {
        if (message[i] == '\n')
        {
            strcat(str, "\\n");
            j += 2;
            continue;
        }
        else if (message[i] == '\r')
        {
            strcat(str, "\\r");
            j += 2;
            continue;
        }
        str[j] = message[i];
        str[j + 1] = 0;
        j++;
    }
    return str;
}

int main()
{
    char *msg = "but eventually you will understand\n";
    char *to_print = change_newline(msg);
    printf("%s\n", to_print);
}