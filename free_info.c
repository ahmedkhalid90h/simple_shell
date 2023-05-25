#include "shell.h"

/**
 * free_info - frees info_t struct fields and sets them to NULL
 * @info: struct address to free
 * @all_re: true if freeing all fields of struct, false if only freeing argv
 */
void free_info(info_t *info, int all_re)
{
	free_string_list(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all_re)
	{
		if (!info->cmd_buf)
			{
				free(info->arg);
			}
		if (info->env)
			{
				free_list(&(info->env));
			}
		if (info->alias)
			{
				free_list(&(info->alias));
			}
		free_string_list(info->environ);
			info->environ = NULL;
		_free_buffer((void **)info->cmd_buf);
		if (info->readfd > 2)
			{
				close(info->readfd);
			}
		_putchar(BUF_FLUSH);
	}
}
