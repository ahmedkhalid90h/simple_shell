#include "shell.h"

/**
 * is_delimeter_char - checks if character is a delimeter or not
 * @cha: the char to check
 * @delimeter: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delimeter_char(char cha, char *delimeter)
{
    int i;
    for (i = 0; delimeter[i] != '\0'; i++) {
        if (delimeter[i] == cha) {
            return 1;
        }
    }
    return 0;
}
