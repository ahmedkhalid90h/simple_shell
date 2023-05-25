#include "shell.h"

/**
 * print_alias - prints an alias string and value
 * @node: the alias node to print
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p_h = NULL, *a = NULL;

	if (node)
	{
		p_h = _strchr(node->str, '=');
		for (a = node->str; a <= p_h; a++)
			{
				_putchar(*a);
			}
		_putchar('\'');
		_puts(p_h + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
