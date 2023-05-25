#include "shell.h"

/**
 * unset_al - sets alias to string ansd value
 * @info: parameter struct alias given
 * @stri: the string alias and value delimited by '='
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_al(info_t *info, char *stri)
{
	char *p_q, c;
	int rets;

	p_q = _strchr_yu(stri, '=');
	if (!p_q)
		return (1);
	c = *p_q;
	*p_q = 0;
	rets = delete_de_idx(&(info->alias),
	gt_de_idx(info->alias, de_starts(info->alias, stri, -1)));
	*p_q = c;
	return (rets);
}
