#include "shell.h"

/**
 * _putchar - writes the character c to stdout STDOUT
 * @put_char_c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char put_char_c)
{
	static int i_dt;
	static char buf[WRITE_BUF_SIZE];

	if (put_char_c == BUF_FLUSH || i_dt >= WRITE_BUF_SIZE)
	{
		write(1, buf, i_dt);
		i_dt = 0;
	}
	if (put_char_c != BUF_FLUSH)
		buf[i_dt++] = put_char_c;
	return (1);
}
