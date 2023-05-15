#include "shell.h"

/**
 * _free_buf - frees a pointer and NULLs the address or turns an error
 * @ptr_adderss: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int _free_buf(void **ptr_adderss)
{
	if (ptr_adderss && *ptr_adderss)
	{
		free(*ptr_adderss);
		*ptr_adderss = NULL;
		return (1);
	}
	return (0);
}