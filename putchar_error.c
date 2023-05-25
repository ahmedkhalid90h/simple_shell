#include "shell.h"

/**
 * putchar_error - writes the character c to stderr
 * @cha: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int putchar_error(char cha)
{
static int i;
static char buf_ssa[WRITE_BUF_SIZE];

if (cha == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf_ssa, i);
i = 0;
}
if (cha != BUF_FLUSH)
{
buf_ssa[i++] = cha;
}
return (1);
}

