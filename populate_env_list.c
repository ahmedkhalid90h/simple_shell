#include "shell.h"

/**
 * populate_env_list - populates env linked list in shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;

	size_t i;

	for (i = 0; environ[i]; i++)
    {
		add_node_end(&node, environ[i], 0);
    }
	info->env = node;
	return (0);
}