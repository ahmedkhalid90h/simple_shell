#include "shell.h"

/**
 * set_info_initializes - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void set_info_initializes(info_t *info, char **av)
{
	int i = 0;

	info->filename = av[0];
	if (info->arg)
	{
		info->argv = _strtok(info->arg, " \t"); /* up _strtok */
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = strdup(info->arg); /* up  _strdup */
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		/*
		replace_alias(info);
		replace_vars(info);
		*/
	}
}
