#include "shell.h"

/**
 * _err_putchar - writes the character c to stderr STDERR
 * @character: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _err_putchar(char character)
{
	static int i;
	static char buff[WRITE_BUF_SIZE];

	if (character == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buff, i);
		i = 0;
	}
	if (character != BUF_FLUSH)
		buff[i++] = character;
	return (1);
}