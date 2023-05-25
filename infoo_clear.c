#include "shell.h"

/**
 * cle_in - initializes info_t struct members to NULL
 * @info: struct address to initialize
 */
void cle_in(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
