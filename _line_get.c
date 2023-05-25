#include "shell.h"
/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr_q: address of pointer to buffer, preallocated or NULL
 * @leng: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr_q, size_t *leng)
{
	static char buf_ff[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr_q;
	if (p && leng)
		s = *leng;
	if (i == len)
	{
		i = len = 0;
	}
	r = read_buf(info, buf_ff, &len);
	if (r == -1 || (r == 0 && len == 0))
	{
		return (-1);
	}
	c = _strchr_yu(buf_ff + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf_ff) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
	{
		return (p ? free(p), -1 : -1);
	}
	if (s)
		{
		_strncat(new_p, buf_ff + i, k - i);
		}
	else
		{
			_strncpy(new_p, buf_ff + i, k - i + 1);
		}
	s += k - i;
	i = k;
	p = new_p;
	if (leng)
		*leng = s;
	*ptr_q = p;
	return (s);
}

