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
		cle_in(info);
		if (inter_mod(info))
		{
			_puts("$ ");
		}
		putchar_error(BUF_FLUSH);
		r = get_in(info);
		if (r != -1)
		{
			set_t_info(info, av);
			builtin_ret_zwe = che_bul(info);
			if (builtin_ret_zwe == -1)
			{
				find_comed(info);
			}
		}
		else if (inter_mod(info))
		{
			_putchar('\n');
		}
		info_free(info, 0);
	}
	info_free(info, 1);
	if (!inter_mod(info) && info->status)
	{
		exit(info->status);
	}
	if (builtin_ret_zwe == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret_zwe);
}
