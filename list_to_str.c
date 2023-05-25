#include "shell.h"

/**
 * list_to_str - returns an array of strings of the list->str values
 * @head: pointer to first node in list
 *
 * Return: array of strings
 */
char **list_to_str(list_t *head)
{
	list_t *node = head;
	size_t i = list_leng(head), jx;
	char **strs_z;
	char *str;

	if (!head || !i)
	{
		return (NULL);
	}
	strs_z = malloc(sizeof(char *) * (i + 1));
	if (!strs_z)
	{
		return (NULL);
	}
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (jx = 0; jx < i; jx++)
			{
				free(strs_z[jx]);
			}
			free(strs_z);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs_z[i] = str;
	}
	strs_z[i] = NULL;
	return (strs_z);
}
