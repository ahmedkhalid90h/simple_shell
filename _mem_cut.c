#include "shell.h"

/**
 **_memset - fills memory witjesth a constant byte
 *@s: the pointer to the the the memory area
 *@b: the byte to fill the  *s with
 *@n: the amount of the th  bytes to be filled
 *Return: (s) a pointer  bythe theto the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
