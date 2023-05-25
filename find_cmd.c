#include "shell.h"

/**
 * find_cmd - finds a command in PATH or current directory
 * @info: the parameter & return info struct parameter
 *
 * Return: void
 */
void find_cmd(info_t *info)
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
		if (!is_delimeter(info->arg[i], " \t\n"))
			kzw++;
	if (!kzw)
		return;

	path_file = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path_file)
	{
		info->path = path_file;
		create_child(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			create_child(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}
