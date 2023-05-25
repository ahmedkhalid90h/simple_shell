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

/**
 * set_alias - sets alias to string ansd value
 * @info: parameter struct alias given
 * @stri: the string alias and value delimited by '='
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *stri)
{
	char *p_qw;

	p_qw = _strchr(stri, '=');
	if (!p_qw)
		{
		return (1);
		}
	if (!*++p_qw)
		{
		return (unset_alias(info, stri));
		}

	unset_alias(info, stri);
	return (add_node_end(&(info->alias), stri, 0) == NULL);
}

/**
 * print_alias - prints an alias string and value
 * @node: the alias node to print
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p_h = NULL, *a = NULL;

	if (node)
	{
		p_h = _strchr(node->str, '=');
		for (a = node->str; a <= p_h; a++)
			{
				_putchar(*a);
			}
		_putchar('\'');
		_puts(p_h + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias) in bash
 * @info: Structure containing potential arguments. Used to maintain 
 *		  constant function prototype and to check for errors.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p_w = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p_w = _strchr(info->argv[i], '=');
		if (p_w)
			{
				set_alias(info, info->argv[i]);
			}
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

/**
 * replace_alias - replaces an aliases in the tokenized string with its value
 * @info: the parameter struct containing the alias linked list
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p_c;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p_c = _strchr(node->str, '=');
		if (!p_c)
			return (0);
		p_c = _strdup(p_c + 1);
		if (!p_c)
			return (0);
		info->argv[0] = p_c;
	}
	return (1);
}
