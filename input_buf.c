#include "shell.h"

/**
 * input_buf - buffers chained commands line input
 * @info: parameter struct
 * @buff: address of buffer params
 * @leng: address of len var params
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buff, size_t *leng)
{
	ssize_t by_r = 0;
	size_t len_p = 0;

	if (!*leng) /* if nothing left in the buffer, fill it */
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigint_Handler);

		by_r = getline(buff, &len_p, stdin);

		if (by_r > 0)
		{
			if ((*buff)[by_r - 1] == '\n')
			{
				(*buff)[by_r - 1] = '\0'; /* remove trailing newline */
				by_r--;
			}
			info->linecount_flag = 1;

			/* TODO remove comments */

			*leng = by_r;
			info->cmd_buf = buff;
		}
	}
	return (by_r);
}
