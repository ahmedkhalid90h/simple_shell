#include "shell.h"

/**
 * _myunsetenv - Remove an environment variable or variables
 * @info: Structure containing potential arguments. Used to maintain
 *		constant function prototype and to check for errors.
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int u;

	if (info->argc == 1)
	{
		_puts_error("Too few arguements.\n");
		return (1);
	}
	for (u = 1; u <= info->argc; u++)
		_unsetenv(info, info->argv[u]);

	return (0);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *		constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @varqw: the string env var property
 */
int _unsetenv(info_t *info, char *varqw)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !varqw)
	{
		return (0);
	}

	while (node)
	{
		p = sta_with(node->str, varqw);
		if (p && *p == '=')
		{
			info->env_changed = delete_de_idx(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}
