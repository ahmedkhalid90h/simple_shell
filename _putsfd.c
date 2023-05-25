#include "shell.h"

/**
 *_puts_fd - prints an input string or character
 * @string: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *string, int fd) /*not file _putsfd */
{
	int i = 0;

	if (!string)
		return (0);
	while (*string)
	{
		i += _putchar_fd(*string++, fd);
	}
	return (i);
}
