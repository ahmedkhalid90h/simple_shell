#include "shell.h"

/**
 * inter_mod - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int inter_mod(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
