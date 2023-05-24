#include "shell.h"

/**
 * node_starts_with - returns node whose str get starts with
 * @node: pointer to list head
 * @pf: string to match
 * @q: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *pf, char q)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, pf);
		if (p && ((q == -1) || (*p == q)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
