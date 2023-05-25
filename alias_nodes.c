#include "shell.h"

/**
 * get_node_index - gets the index of a node in a list
 * @head: pointer to list head node
 * @node: pointer to the node to find
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
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

/**
 * node_starts_with - returns node whose string starts with prefix and c
 * @node: pointer to list head node
 * @prx: string to match at beginning of node string
 * @c_q: the next character after prefix to match or -1
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prx, char c_q)
{
	char *p_q = NULL;

	while (node)
	{
		p_q = starts_with(node->str, prx);
		if (p_q && ((c_q == -1) || (*p_q == c_q)))
			{
				return (node);
			}
		node = node->next;
	}
	return (NULL);
}

/**
 * delete_node_at_index - deletes node at given index in list
 * @head: address of pointer to first node in list
 * @idx: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int idx)
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
