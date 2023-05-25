#include "shell.h"

/**
 * is_nxt - test if current char in buffer is a chain delimeter or not
 * @info: the parameter struct containing shell variables
 * @buf_zaq: the char buffer to check for delimeters
 * @p: address of current position in buf to check for delimeters
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_nxt(info_t *info, char *buf_zaq, size_t *p)
{
	size_t j = *p;

	if (buf_zaq[j] == '|' && buf_zaq[j + 1] == '|')
	{
		buf_zaq[j] = 0;
		j++;
		info->cmd_buf_type = OR;
	}
	else if (buf_zaq[j] == '&' && buf_zaq[j + 1] == '&')
	{
		buf_zaq[j] = 0;
		j++;
		info->cmd_buf_type = AND;
	}
	else if (buf_zaq[j] == ';') /* found end of this command */
	{
		buf_zaq[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}
