#include "shell.h"

/**
 * prnt_deci - function prints a decimal (integer) number (base 10) to a
 * @input: the input integer to print
 * @fxzw: the filedescriptor to write to (1 for stdout, 2 for stderr)
 *
 * Return: number of characters printed
 */
int prnt_deci(int input, int fxzw)
{
	int (*__putchar)(char) = _putchar;
	int m, count = 0;
	unsigned int _abs_, current;

	if (fxzw == STDERR_FILENO)
		__putchar = putchar_error;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (m = 1000000000; m > 1; m /= 10)
	{
		if (_abs_ / m)
		{
			__putchar('0' + current / m);
			count++;
		}
		current %= m;
	}
	__putchar('0' + current);
	count++;

	return (count);
}
