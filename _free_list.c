#include "shell.h"

/**
 * free_list_node - frees all nodes of a list node
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list_node(list_t **head_ptr)
{
	list_t *current_node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	for (current_node = head; current_node; current_node = next_node)
	{
		next_node = current_node->next;
		free(current_node->str);
		free(current_node);
	}
	*head_ptr = NULL;
}