#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h_e: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h_e)
{
	size_t i = 0;

	while (h_e)
	{
		h_e = h_e->next;
		i++;
	}
	return (i);
}
