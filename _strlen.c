#include "shell.h"

/**
 * _strlen - returns the length of a string or 0 if null
 * @strr: the string whose length to check or null
 *
 * Return: integer length of string
 */
int _strlen(char *strr)
{
	int i = 0;

	if (!strr)
		return (0);

	while (*strr++)
		i++;
	return (i);
}
