#include "shell.h"

/**
 * in_bu - buffers chained commands from stdin
 * @info: parameter struct containing shell variables
 * @bufzz: address of buffer pointer
 * @leng: address of len var to store buffer length
 *
 * Return: bytes read
 */
ssize_t in_bu(info_t *info, char **bufzz, size_t *leng)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*leng) /* if nothing left in the buffer, fill it */
	{
		free(*bufzz);
		*bufzz = NULL;
		signal(SIGINT, sigintHandler);

		r = _getline(info, bufzz, &len_p);

		if (r > 0)
		{
			if ((*bufzz)[r - 1] == '\n')
			{
				(*bufzz)[r - 1] = '\0'; /* remove trailing newline */
				r--;
			}
			info->linecount_flag = 1;
			comt_handl(*bufzz);
			*leng = r;
			info->cmd_buf = bufzz;
		}
	}
	return (r);
}
