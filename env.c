#include "shell.h"

/**
 * _env - prints the current environment variables
 * @info: Structure containing potential arguments. Used to maintain and
 *		  constant function prototype and add future functionality.
 * Return: Always 0
 */
int _env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * print_list_str - prints only the str element of a list_t linked list of
 * @h: pointer to first node of list
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t ix = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		ix++;
	}
	return (ix);
}

/**
 * env_list - populates env linked list with environment variables
 * @info: Structure containing potential arguments. Used to maintain and
 *		  constant function prototype. Not used in this function.
 * Return: Always 0
 */
int env_list(info_t *info)
{
	list_t *node = NULL;
	size_t iz;

	for (iz = 0; environ[iz]; iz++)
	{
		add_de_end(&node, environ[iz], 0);
	}
	info->env = node;
	return (0);
}
