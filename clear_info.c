#include "shell.h"

/**
 * clear_info - initializes info_t struct members to NULL
 * @info: struct address to initialize
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
