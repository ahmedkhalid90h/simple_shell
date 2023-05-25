#include "shell.h"

/**
 * repla_vars - replaces vars in the tokenized string with their
 * @info: the parameter struct for the program
 *
 * Return: 1 if replaced, 0 otherwise
 */
int repla_vars(info_t *info)
{
	int i = 0;
	list_t *node_s;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			repla_str(&(info->argv[i]), _strdup(_itoa(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			repla_str(&(info->argv[i]), _strdup(_itoa(getpid(), 10, 0)));
			continue;
		}
		node_s = de_starts(info->env, &info->argv[i][1], '=');
		if (node_s)
		{
			repla_str(&(info->argv[i]), _strdup(_strchr_yu(node_s->str, '=') + 1));
			continue;
		}
		repla_str(&info->argv[i], _strdup(""));
	}
	return (0);
}
