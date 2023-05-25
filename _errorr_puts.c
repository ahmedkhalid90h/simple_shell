#include "shell.h"

/**
 *_puts_error - prints an input string the standard error
 * @str: the string to be printed to stderr
 *
 * Return: Nothing
 */
void _puts_error(char *str)
{
int i = 0;

if (!str)
{
return;
}
while (str[i] != '\0')
{
putchar_error(str[i]);
i++;
}
}

