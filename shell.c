#include "shell.h"

/**
 * main - entry point check true or false
 * @argc: arg count
 * @agrv: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	info_t info[] = {{NULL, NULL, NULL, 0, 0, 0, 0, NULL,
	NULL, NULL, NULL, 0, 0, NULL,
	0, 0}};
	int fp;

	if (argc == 2)
	{
		fp = open(argv[1], O_RDONLY);
		if (fp == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_err_puts(argv[0]);
				_err_puts(": 0: Can't open ");
				_err_puts(argv[1]);
				_err_putchar('\n');
				_err_putchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd_f = fp;
	}
	populate_env_list(info);
	hsh(info, argv);
	return (EXIT_SUCCESS);
}
