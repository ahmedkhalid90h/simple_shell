#include "shell.h"

/**
 *_error_puts - prints an input string the standard error
 * @str: the string to be printed to stderr
 *
 * Return: Nothing
 */
void _error_puts(char *str)
{
	int i = 0;

	if (!str)
		{
            return;
        }
	while (str[i] != '\0')
	{
		_error_putchar(str[i]);
		i++;
	}
}
