#include "shell.h"

/**
 * set_t_info - initializes info_t struct with arguments
 * @info: struct address to initialize
 * @av: argument vector to initialize with
 */
void set_t_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = _strtok(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
		;
		info->argc = i;
		replace_al(info);
		repla_vars(info);
	}
}

