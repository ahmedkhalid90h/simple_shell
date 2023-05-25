#include "shell.h"

/**
 * list_free_str - frees a string of strings (array of strings)
 * @pp_zz: string of strings to free
 */
void list_free_str(char **pp_zz)
{
	char **a = pp_zz;

	if (!pp_zz)
	{
		return;
	}
	while (*pp_zz)
	{
		free(*pp_zz++);
	}
	free(a);
}
