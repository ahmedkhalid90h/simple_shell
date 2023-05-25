#include "shell.h"

/**
 *_treefd - prints an input string or character
 * @string: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of chars put
 */
int _treefd(char *string, int fd)
{
	int i = 0;

	if (!string)
		return (0);
	while (*string)
	{
		i += _puy_fd(*string++, fd);
	}
	return (i);
}
