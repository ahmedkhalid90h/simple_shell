#include "shell.h"

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
