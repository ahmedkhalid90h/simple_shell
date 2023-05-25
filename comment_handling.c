#include "shell.h"

/**
 * comment_handling - function replaces first instance of '#' with '\0' in buf
 * @buf_qw: address of the string to modify in place
 *
 * Return: Always 0;
 */
void comment_handling(char *buf_qw)
{
	int idx;

	for (idx = 0; buf_qw[idx] != '\0'; idx++)
		if (buf_qw[idx] == '#' && (!idx || buf_qw[idx - 1] == ' '))
		{
			buf_qw[idx] = '\0';
			break;
		}
}
