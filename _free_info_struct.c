#include "shell.h"

/**
 * _free_info_struct - frees info_t struct fields or false
 * @info: struct address
 * @all_tr: true if freeing all fields
 */
void _free_info_struct(info_t *info, int all_tr)
{
	free_str_list(info->argv_x);
	info->argv_x= NULL;
	info->path_f = NULL;
	if (all_tr)
	{
		if (!info->cmd_buf)
			free(info->arg_c);
		if (info->env)
			free_list_node(&(info->env));
		if (info->alias)
			free_list_node(&(info->alias));
		free_str_list(info->environ);
			info->environ = NULL;
		_free_buf((void **)info->cmd_buf);
		if (info->readfd_f > 2)
			close(info->readfd_f);
		putchar(BUF_FLUSH); /* up to _putchar */
	}
}