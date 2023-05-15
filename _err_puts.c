#include "shell.h"

/**
 *_err_puts - prints an input string
 * @string: the string to be printed
 *
 * Return: Nothing
 */
void _err_puts(char *string)
{
	int inx;
	if (!string)
		return;
	for ( inx = 0; string[inx] != '\0'; inx++)
	{
		_err_putchar(string[inx]);  
	}
}
