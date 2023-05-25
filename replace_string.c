#include "shell.h"

/**
 * replace_string - replaces string with new string
 * @old_as: address of old string to replace
 * @new_f: new string to replace with
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old_as, char *new_f)
{
	free(*old_as);
	*old_as = new_f;
	return (1);
}
