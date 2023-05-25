#include "shell.h"

/**
 * che_bul - finds a builtin command
 * @info: the parameter & return info struct for the shell
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int che_bul(info_t *info)
{
	int idx, built_in_ret_d = -1;
	builtin_table builtintbl[] = {
		{"exit", exit_shell},
		{"env", _env},
		{"setenv", _my_setenv},
		{"unsetenv", _myunsetenv},
		{"cd", _change_dir},
		{"alias", _myalias},
		{NULL, NULL}};

	for (idx = 0; builtintbl[idx].type; idx++)
		if (_strcmp(info->argv[0], builtintbl[idx].type) == 0)
		{
			info->line_count++;
			built_in_ret_d = builtintbl[idx].func(info);
			break;
		}
	return (built_in_ret_d);
}
