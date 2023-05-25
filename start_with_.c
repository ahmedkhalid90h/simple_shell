#include "shell.h"

/**
 * sta_with - checks if needle starts with haystack and returns address
 * @hay: string to search in for substring
 * @needle: the substring to find in haystack
 *
 * Return: address of next char of haystack or NULL
 */
char *sta_with(const char *hay, const char *needle)
{
	while (*needle)
		if (*needle++ != *hay++)
		{
			return (NULL);
		}
	return ((char *)hay);
}

