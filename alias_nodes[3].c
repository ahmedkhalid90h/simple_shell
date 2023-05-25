#include "shell.h"
/**
 * add_node_end - adds a node to the end of the list or at the beginning
 * @head: address of pointer to head node of list
 * @str: str field of node to add
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *stri, int numb)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = numb;
	if (stri)
	{
		new_node->str = _strdup(stri);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			{
				node = node->next;
			}
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}
