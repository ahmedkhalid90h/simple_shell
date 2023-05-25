#include "shell.h"

/**
 * populate_env - populates env linked list with environment variables
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype. Not used in this function.
 * Return: Always 0
 */
int populate_env(info_t *info)
{
	list_t *node = NULL;
	size_t iz;

	for (iz = 0; environ[iz]; iz++)
	{
		add_de_end(&node, environ[iz], 0);
	}
	info->env = node;
	return (0);
}
