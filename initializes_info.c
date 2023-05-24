#include "shell.h"

/**
 * initializes_info - initializes info_t struct clear code
 * @info: struct address
 */
void initializes_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path_f = NULL;
	info->argc = 0;
}
