#include"shell.h"

/**
 * delete_node_at_index - deletes the node at given the index
 * @head: address of pointer to the first the node
 * @m: index of node to deleting
 *
 * Return: 1 on success , return 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int m)
{
	list_t *node, *prev_node;
	unsigned int w = 0;

	if (!head || !*head)
		return (0);

	if (!m)
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
		if (w == m)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		w++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}
