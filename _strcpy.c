#include "shell.h"

/**
 * _strcpy - copies a string or n bytes of a string
 * @dest: the destination destination
 * @src: the source destination
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 **_strncpy - copies a string
 *@dest_qws: the destination string to be copied to
 *@src_qwe: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest_qws, char *src_qwe, int n)
{
	int i, j;
	char *s = dest_qws;

	i = 0;
	while (src_qwe[i] != '\0' && i < n - 1)
	{
		dest_qws[i] = src_qwe[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest_qws[j] = '\0';
			j++;
		}
	}
	return (s);
}
