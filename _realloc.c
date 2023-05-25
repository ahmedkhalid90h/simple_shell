#include "shell.h"
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
		{
		return (malloc(new_sqz));
		}
	if (!new_sqz)
		{
		return (free(ptr_qw), NULL);
		}
	if (new_sqz == old_sqz)
	{
		return (ptr_qw);
	}

	p = malloc(new_sqz);
	if (!p)
	{
		return (NULL);
	}

	old_sqz = old_sqz < new_sqz ? old_sqz : new_sqz;
	while (old_sqz--)
		p[old_sqz] = ((char *)ptr_qw)[old_sqz];
	free(ptr_qw);
	return (p);
}

