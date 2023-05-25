#include "shell.h"

/**
 * find_comed - finds a command in PATH or current directory
 * @info: the parameter & return info struct parameter
 *
 * Return: void
 */
void find_comed(info_t *info)
{
	char *path_file = NULL;
	int i, kzw;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, kzw = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			kzw++;
	if (!kzw)
		return;

	path_file = find_th(info, _getenv(info, "PATH="), info->argv[0]);
	if (path_file)
	{
		info->path = path_file;
		cre_ch(info);
	}
	else
	{
		if ((inter_mod(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_comid(info, info->argv[0]))
			cre_ch(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			error_print(info, "not found\n");
		}
	}
}
