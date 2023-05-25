#include "shell.h"

/**
 * delete_de_idx - deletes node at given index in list
 * @head: address of pointer to first node in list
 * @idx: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_de_idx(list_t **head, unsigned int idx)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!idx)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == idx)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}
