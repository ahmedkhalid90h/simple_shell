#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 **_strncat - concatenates two strings
 *@qqyyou: the first string
 *@src: the second string
 *@nq: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *qqyyou, char *src, int nq)
{
	int i, j;
	char *s = qqyyou;

	i = 0;
	j = 0;
	while (qqyyou[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nq)
	{
		qqyyou[i] = src[j];
		i++;
		j++;
	}
	if (j < nq)
		qqyyou[i] = '\0';
	return (s);
}
