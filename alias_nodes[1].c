#include "shell.h"

/**
 * de_starts - returns node whose string starts with prefix and c
 * @node: pointer to list head node
 * @prx: string to match at beginning of node string
 * @c_q: the next character after prefix to match or -1
 *
 * Return: match node or null
 */
list_t *de_starts(list_t *node, char *prx, char c_q)
{
	char *p_q = NULL;

	while (node)
	{
		p_q = sta_with(node->str, prx);
		if (p_q && ((c_q == -1) || (*p_q == c_q)))
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}
