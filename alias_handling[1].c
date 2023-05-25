#include "shell.h"

/**
 * unset_alias - sets alias to string ansd value
 * @info: parameter struct alias given
 * @stri: the string alias and value delimited by '='
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *stri)
{
	char *p_q, c;
	int rets;

	p_q = _strchr(stri, '=');
	if (!p_q)
		return (1);
	c = *p_q;
	*p_q = 0;
	rets = delete_node_at_index(&(info->alias),
	get_node_index(info->alias, node_starts_with(info->alias, stri, -1)));
	*p_q = c;
	return (rets);
}
