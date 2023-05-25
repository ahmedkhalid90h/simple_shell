#include "shell.h"

/**
 * set_al - sets alias to string ansd value
 * @info: parameter struct alias given
 * @stri: the string alias and value delimited by '='
 *
 * Return: Always 0 on success, 1 on error
 */
int set_al(info_t *info, char *stri)
{
	char *p_qw;

	p_qw = _strchr_yu(stri, '=');
	if (!p_qw)
		{
		return (1);
		}
	if (!*++p_qw)
		{
		return (unset_al(info, stri));
		}

	unset_al(info, stri);
	return (add_de_end(&(info->alias), stri, 0) == NULL);
}
