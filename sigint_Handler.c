#include "shell.h"

/**
 * sigint_Handler - blocks ctrl-C or Ctrl
 * @signal_number: the signal number
 *
 * Return: void
 */
void sigint_Handler(__attribute__((unused))int signal_number)
{
	puts("\n");   /* up _puts_str */
	puts("$ ");   /* up _puts_str */
	putchar(BUF_FLUSH);   /* up _putchar */
}