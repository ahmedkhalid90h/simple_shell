#include "shell.h"

/**
 * print_decimal_num - function prints a decimal (integer) number (base 10)
 * @inputs: the input
 * @fdesc: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_decimal_num(int inputs, int fdesc)
{
	int (*__putchar)(char) = _putchar;
	int inx = 1000000000, count_num = 0;
	unsigned int _abs, curr;

	if (fdesc == STDERR_FILENO)
		__putchar = _err_putchar;
	if (inputs < 0)
	{
		_abs = -inputs;
		__putchar('-');
		count_num++;
	}
	else
		_abs = inputs;
	curr = _abs;
	while (inx > 1)
	{
		if (_abs / inx)
		{
			__putchar('0' + curr / inx);
			count_num++;
		}
		curr %= inx;
		inx /= 10;
	}
	__putchar('0' + curr);
	count_num++;

	return (count_num);
}
