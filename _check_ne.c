#include "shell.h"

/**
 * che_ne - checks we should continue chaining based on last status and type
 * @info: the parameter struct containing shell info
 * @buffa: the char buffer to check
 * @p_qe: address of current position in buf to update
 * @i: starting position in buf to check
 * @leng: length of buf to check
 *
 * Return: Void
 */
void che_ne(info_t *info, char *buffa, size_t *p_qe, size_t i, size_t leng)
{
	size_t j = *p_qe;

	if (info->cmd_buf_type == AND)
	{
		if (info->status)
		{
			buffa[i] = 0;
			j = leng;
		}
	}
	if (info->cmd_buf_type == OR)
	{
		if (!info->status)
		{
			buffa[i] = 0;
			j = leng;
		}
	}

	*p_qe = j;
}
