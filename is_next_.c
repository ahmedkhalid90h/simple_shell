#include "shell.h"

/**
 * is_next_c - test if current char in buffer is a chain delimeter line
 * @info: the parameter struct
 * @buffer: the char buffer
 * @address: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_next_c(info_t *info, char *buffer, size_t *address)
{
	size_t j = *address;

	if (buffer[j] == '|' && buffer[j + 1] == '|')
	{
		buffer[j] = 0;
		j++;
		info->cmd_buf_type = OR;
	}
	else if (buffer[j] == '&' && buffer[j + 1] == '&')
	{
		buffer[j] = 0;
		j++;
		info->cmd_buf_type = AND;
	}
	else if (buffer[j] == ';') /* found end of this command */
	{
		buffer[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CHAIN;
	}
	else
		return (0);
	*address = j;
	return (1);
}
