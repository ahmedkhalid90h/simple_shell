#include "shell.h"

/**
 * _free_buffer - frees a pointer and NULLs the address of the pointer
 * @ptr_add: address of the pointer to free and NULL
 *
 * Return: 1 if freed, otherwise 0.
 */

int _free_buffer(void **ptr_add)
{
	if (ptr_add && *ptr_add)
	{
		free(*ptr_add);
		*ptr_add = NULL;
		return (1);
	}
	return (0);
}
