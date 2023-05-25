#include "shell.h"

/**
 * _my_setenv - Initialize a new environment variable,
 *			 or modify an existing one or print all env vars
 * @info: Structure containing potential arguments. Used to maintain
 *		constant function prototype and to print all env vars
 *  Return: Always 0
 */
int _my_setenv(info_t *info)
{
	if (info->argc != 3)
	{
		_puts_error("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		{
		return (0);
		}
	return (1);
}

/**
 * _setenv - Initialize a new environment variable,
 *			 or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *		constant function prototype.
 * @var_sq: the string env var property or name
 * @val: the string env var value ro be set
 *  Return: Always 0
 */
int _setenv(info_t *info, char *var_sq, char *val)
{
	char *buf = NULL;
	list_t *node;
	char *p_q;

	if (!var_sq || !val)
		return (0);

	buf = malloc(_strlen(var_sq) + _strlen(val) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var_sq);
	_strcat(buf, "=");
	_strcat(buf, val);
	node = info->env;
	while (node)
	{
		p_q = sta_with(node->str, var_sq);
		if (p_q && *p_q == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_de_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
