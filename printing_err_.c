#include "shell.h"

/**
 * error_print - prints an error message to stderr
 * @info: the parameter & return info struct for the program
 * @estr: string containing specified error type to print
 * Return: 0 if no numbers in string, converted number otherwise
 *		-1 on error
 */
void error_print(info_t *info, char *estr)
{
	_puts_error(info->fname);
	_puts_error(": ");
	prnt_deci(info->line_count, STDERR_FILENO);
	_puts_error(": ");
	_puts_error(info->argv[0]);
	_puts_error(": ");
	_puts_error(estr);
}
