#include "shell.h"

/**
 * _myalias - mimics the alias builtin (man alias) in bash
 * @info: Structure containing potential arguments. Used to maintain
 *		  constant function prototype and to check for errors.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p_w = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_al(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p_w = _strchr_yu(info->argv[i], '=');
		if (p_w)
		{
			set_al(info, info->argv[i]);
		}
		else
			print_al(de_starts(info->alias, info->argv[i], '='));
	}

	return (0);
}
