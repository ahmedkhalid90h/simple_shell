#include "shell.h"

/**
 * find_path_f - finds this cmd in the PATH string and returns
 * @info: the info struct
 * @path_string: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path_f(info_t *info, char *path_string, char *cmd)
{
	int idx52 = 0, curr_pos = 0;
	char *path;

	if (!path_string)
		return (NULL);
	if ((strlen(cmd) > 2) && starts_with_needl(cmd, "./")) /* up to _strlen */
	{
		if (is_cmd_(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!path_string[idx52] || path_string[idx52] == ':')
		{
			path = dupl_chars(path_string, curr_pos, idx52);
			if (!*path)
				strcat(path, cmd); /* up to _strcat */
			else
			{
				strcat(path, "/"); /* up to _strcat */
				strcat(path, cmd); /* up to _strcat */
			}
			if (is_cmd_(info, path))
				return (path);
			if (!path_string[idx52])
				break;
			curr_pos = idx52;
		}
		idx52++;
	}
	return (NULL);
}
