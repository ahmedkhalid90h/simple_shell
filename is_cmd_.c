#include "shell.h"

/**
 * is_cmd_ - determines if a file is an executable command line true or false
 * @info: the info struct
 * @path_f: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd_(info_t *info, char *path_f)
{
	struct stat st;

	(void)info;
	if (!path_f || stat(path_f, &st))
		return (0);

	
	
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	
	return (0);
}
