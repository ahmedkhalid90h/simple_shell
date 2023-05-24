#include "shell.h"

/**
 * print_err - prints an error message if an error occurs
 * @info: the parameter & return info struct
 * @e_string: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_err(info_t *info, char *e_string)
{
	_err_puts(info->filename);
	_err_puts(": ");
	print_decimal_num(info->line_count_, STDERR_FILENO);
	_err_puts(": ");
	_err_puts(info->argv_x[0]);
	_err_puts(": ");
	_err_puts(e_string);
}
