#include "shell.h"

/**
 *_puts - prints an input string the standard output
 * @string: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *string)
{
int inx;

if (!string)
return;
for (inx = 0; string[inx] != '\0'; inx++)
{
_putchar(string[inx]);
}
}
