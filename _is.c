#include "shell.h"
/**
 **_strchr - locates a character in a string
 *@sq: the string to be parsed
 *@cdc: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *sq, char cdc)
{
do {
if (*sq == cdc)
return (sq);
} while (*sq++ != '\0');

return (NULL);
}

/**
 * _realloc - reallocates a block of memory that was previously allocated
 * @ptr_qw: pointer to old block
 * @old_sqz: byte size of previous block
 * @new_sqz: byte size of new block
 *
 * Return: pointer to new block, or NULL on failure
 */
void *_realloc(void *ptr_qw, unsigned int old_sqz, unsigned int new_sqz)
{
	char *p;

	if (!ptr_qw)
		return (malloc(new_sqz));
	if (!new_sqz)
		return (free(ptr_qw), NULL);
	if (new_sqz == old_sqz)
		return (ptr_qw);

	p = malloc(new_sqz);
	if (!p)
		return (NULL);

	old_sqz = old_sqz < new_sqz ? old_sqz : new_sqz;
	while (old_sqz--)
		p[old_sqz] = ((char *)ptr_qw)[old_sqz];
	free(ptr_qw);
	return (p);
}
