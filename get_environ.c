#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ list
 * @info: Structure containing potential arguments. Used to maintain
 *		  constant function prototype. Not used in this function.
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_str(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}
