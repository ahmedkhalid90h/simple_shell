#include "shell.h"

/**
 * list_to_str - returns an array of strings of the list->str
 * @head_node: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_str(list_t *head_node)
{
		list_t *node = head_node;
	size_t i = list_length(head_node), j;
	char **strs;
	char *str;

	if (!head_node || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}
