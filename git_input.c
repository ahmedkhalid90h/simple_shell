#include "shell.h"

/**
 * get_in - gets a line minus the newline character
 * @info: parameter struct containing shell variables
 *
 * Return: bytes read
 */
ssize_t get_in(info_t *info)
{
	static char *buf_zw; /* the ';' command chain buffer */
	static size_t i, dx, leng;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = in_bu(info, &buf_zw, &leng);
	if (r == -1) /* EOF */
		return (-1);
	if (leng)	/* we have commands left in the chain buffer */
	{
		dx = i; /* init new iterator to current buf position */
		p = buf_zw + i; /* get pointer for return */

		che_ne(info, buf_zw, &dx, i, leng);
		while (dx < leng) /* iterate to semicolon or end */
		{
			if (is_nxt(info, buf_zw, &dx))
				break;
			dx++;
		}

		i = dx + 1; /* increment past nulled ';'' */
		if (i >= leng) /* reached end of buffer? */
		{
			i = leng = 0; /* reset position and length */
			info->cmd_buf_type = NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buf_zw; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}
