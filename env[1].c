#include "shell.h"

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_err_puts(h->str ? h->str : "(nil)");
		_err_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
