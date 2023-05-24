#include "shell.h"


/**
 * check_next_f - checks if  chaining based on last status done
 * @info: the parameter struct
 * @u: the char buffer
 * @pos: address of current position in buf
 * @s: starting position in buf
 * @l: length of buf
 *
 * Return: void
 */
void check_next_f(info_t *info, char *u, size_t *pos, size_t s, size_t l)
{
	size_t j = *pos;

	if (info->cmd_buf_type == AND)
	{
		if (info->status)
		{
			u[s] = 0;
			j = l;
		}
	}
	if (info->cmd_buf_type == OR)
	{
		if (!info->status)
		{
			u[s] = 0;
			j = l;
		}
	}

	*pos = j;
}
