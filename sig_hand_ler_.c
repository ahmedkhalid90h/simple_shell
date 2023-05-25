#include "shell.h"

/**
 * sigintHandler - blocks ctrl-C from exiting shell
 * @sig_count: the signal number (unused)
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_count)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
