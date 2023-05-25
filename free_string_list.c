#include "shell.h"

/**
 * free_string_list - frees a string of strings (array of strings)
 * @pp_zz: string of strings to free
 */
void free_string_list(char **pp_zz)
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
