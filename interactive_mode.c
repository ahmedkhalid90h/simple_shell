#include "shell.h"

/**
 * interactive_mode - returns true if shell is interactive mode true or false
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd_f <= 2);
}