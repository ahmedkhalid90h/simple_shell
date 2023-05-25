#include "shell.h"

/**
 * list_free - frees all nodes of a list and sets head to NULL (safe)
 * @head_ptr: address of pointer to head node of list to free
 *
 * Return: void
 */
void list_free(list_t **head_ptr)
{
	list_t *node, *next_node_f, *head_qz;

	if (!head_ptr || !*head_ptr)
	{
		return;
	}
	head_qz = *head_ptr;
	node = head_qz;
	while (node)
	{
		next_node_f = node->next;
		free(node->str);
		free(node);
		node = next_node_f;
	}
	*head_ptr = NULL;
}
