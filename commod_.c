#include "shell.h"

/**
 * is_comid - determines if a file is an executable command or not
 * @info: the info struct containing shell variables
 * @path_file: path to the file to check
 *
 * Return: 1 if true, 0 otherwise
 */
int is_comid(info_t *info, char *path_file)
{
	struct stat st;

	(void)info;
	if (!path_file || stat(path_file, &st))
	{
		return (0);
	}

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
