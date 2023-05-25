#include "shell.h"

/**
 * gt_de_idx - gets the index of a node in a list
 * @head: pointer to list head node
 * @node: pointer to the node to find
 *
 * Return: index of node or -1
 */
ssize_t gt_de_idx(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
		{
			return (i);
		}
		head = head->next;
		i++;
	}
	return (-1);
}
