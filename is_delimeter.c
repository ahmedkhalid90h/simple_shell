#include "shell.h"

/**
 * is_delimeter - checks if character is a delimeter or not
 * @c_zq: the char to check if delimeter or not
 * @delim: the delimeter string to check against
 * Return: 1 if true, 0 if false
 */
int is_delimeter(char c_zq, char *delim)
{
	while (*delim)
		if (*delim++ == c_zq)
			{
				return (1);
			}
	return (0);
}
