#include "shell.h"

/**
 * find_th - finds this cmd in the PATH string and returns full path if found
 * @info: the info struct containing shell info variables
 * @path_str: the PATH string to search through
 * @cmd_d: the cmd to find in the PATH string (or current directory)
 *
 * Return: full path of cmd if found or NULL
 */
char *find_th(info_t *info, char *path_str, char *cmd_d)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!path_str)
	{
		return (NULL);
	}
	if ((_strlen(cmd_d) > 2) && sta_with(cmd_d, "./"))
	{
		if (is_comid(info, cmd_d))
		{
			return (cmd_d);
		}
	}
	while (1)
	{
		if (!path_str[i] || path_str[i] == ':')
		{
			path = dup_ch(path_str, curr_pos, i);
			if (!*path)
				_strcat(path, cmd_d);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd_d);
			}
			if (is_comid(info, path))
				return (path);
			if (!path_str[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
