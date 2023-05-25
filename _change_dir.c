#include "shell.h"
/**
 * _change_dir - changes the current directory of the process to the one
 * @info: Structure containing potential arguments. Used to maintain a
 *		  constant function prototype and to check for errors. Also used
 *  Return: Always 0
 */
int _change_dir(info_t *info)
{
	char *s, *dir_qw, buffer_ss[1024];
	int chdir_ret;

	s = getcwd(buffer_ss, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure  emsg here<<\n");
	if (!info->argv[1])
	{
		dir_qw = _getenv(info, "HOME=");
		if (!dir_qw)
			chdir_ret =
			chdir((dir_qw = _getenv(info, "PWD=")) ? dir_qw : "/");
		else
			chdir_ret = chdir(dir_qw);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir_qw = _getenv(info, "OLDPWD=")) ? dir_qw : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		error_print(info, "can't  cd to ");
		_puts_error(info->argv[1]), putchar_error('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer_ss, 1024));
	}
	return (0);
}
