#include "shell.h"

/**
 * replace_al - replaces an aliases in the tokenized string with its value
 * @info: the parameter struct containing the alias linked list
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_al(info_t *info)
{
	int i;
	list_t *node;
	char *p_c;

	for (i = 0; i < 10; i++)
	{
		node = de_starts(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p_c = _strchr_yu(node->str, '=');
		if (!p_c)
			return (0);
		p_c = _strdup(p_c + 1);
		if (!p_c)
			return (0);
		info->argv[0] = p_c;
	}
	return (1);
}

