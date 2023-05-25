#include "shell.h"

/**
 * exit_shell - exits the shell with a given exit status or error number
 * @info: Structure containing potential arguments. Used to maintain and
 *		  constant function prototype. Not used in this function. Added for
 *  Return: exits with a given exit status
 *		 (0) if info.argv[0] != "exit"
 */
int exit_shell(info_t *info)
{
	int exitch;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		exitch = _atoi_error(info->argv[1]);
		if (exitch == -1)
		{
			info->status = 2;
			error_print(info, "Illegal number: ");
			_puts_error(info->argv[1]);
			putchar_error('\n');
			return (1);
		}
		info->err_num = _atoi_error(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
