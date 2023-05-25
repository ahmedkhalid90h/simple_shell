#include "shell.h"

/**
 * _getenv - gets the value of an environ variable in the environment
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *poin;

	while (node)
	{
		poin = sta_with(node->str, name);
		if (poin && *poin)
			{
			return (poin);
			}
		node = node->next;
	}
	return (NULL);
}
