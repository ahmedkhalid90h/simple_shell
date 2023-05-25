#include "shell.h"

/**
 * hsh - main shell loop function
 * @info: the parameter & return info struct (unused)
 * @av: the argument vector from main() (unused)
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret_zwe = 0;

	while (r != -1 && builtin_ret_zwe != -2)
	{
		clear_info(info);
		if (interactive(info))
			{
				_puts("$ ");
			}
		_error_putchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_ret_zwe = check_builtin(info);
			if (builtin_ret_zwe == -1)
				{
					find_cmd(info);
				}
		}
		else if (interactive(info))
			{
				_putchar('\n');
			}
		free_info(info, 0);
	}
	free_info(info, 1);
	if (!interactive(info) && info->status)
		{
			exit(info->status);
		}
	if (builtin_ret_zwe == -2)
	{
		if (info->err_num == -1)
			{
				exit(info->status);
			}
		exit(info->err_num);
	}
	return (builtin_ret_zwe);
}
