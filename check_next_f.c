#include "shell.h"


/**
 * check_next_f - checks if we should continue chaining based on last status done
 * @info: the parameter struct
 * @buf: the char buffer
 * @pos: address of current position in buf
 * @start: starting position in buf
 * @length: length of buf
 *
 * Return: void
 */
void check_next_f(info_t *info, char *buf, size_t *pos, size_t start, size_t length)
{
	size_t j = *pos;

	if (info->cmd_buf_type == AND)
	{
		if (info->status)
		{
			buf[start] = 0;
			j = length;
		}
	}
	if (info->cmd_buf_type == OR)
	{
		if (!info->status)
		{
			buf[start] = 0;
			j = length;
		}
	}

	*pos = j;
}
