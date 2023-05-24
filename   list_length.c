#include "shell.h"

/**
 * list_length - determines length of linked list
 * @node_poi: pointer to first node
 *
 * Return: size of list
 */
size_t list_length(const list_t *node_poi)
{
	size_t i = 0;

	while (node_poi)
	{
		node_poi = node_poi->next;
		i++;
	}
	return (i);
}
