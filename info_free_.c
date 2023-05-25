#include "shell.h"

/**
 * info_free - frees info_t struct fields and sets them to NULL
 * @info: struct address to free
 * @all_re: true if freeing all fields of struct, false if only freeing argv
 */
void info_free(info_t *info, int all_re)
{
	list_free_str(info->argv);
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
			list_free(&(info->env));
		}
		if (info->alias)
		{
			list_free(&(info->alias));
		}
		list_free_str(info->environ);
			info->environ = NULL;
		_buffer_free((void **)info->cmd_buf);
		if (info->readfd > 2)
		{
			close(info->readfd);
		}
		_putchar(BUF_FLUSH);
	}
}
