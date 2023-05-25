#include "shell.h"
/**
 **_strchr_yu - locates a character in a string
 *@sq: the string to be parsed
 *@cdc: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr_yu(char *sq, char cdc)
{
do {
if (*sq == cdc)
return (sq);
} while (*sq++ != '\0');

return (NULL);
}
