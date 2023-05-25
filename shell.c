#include "shell.h"

/**
 * main - entry point for shell
 * @argc: arg count (unused) (for now)
 * @argv: arg vector (unused) (for now)
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	info_t info[] = {{NULL, NULL, NULL, 0, 0, 0, 0,
	NULL, NULL, NULL, NULL, 0, 0, NULL, 0, 0}};
	int s_fd;

	if (argc == 2)
	{
		s_fd = open(argv[1], O_RDONLY);
		if (s_fd == -1)
		{
			if (errno == EACCES)
			{
				exit(126);
			}
			if (errno == ENOENT)
			{
				_puts_error(argv[0]);
				_puts_error(": 0: Can't open ");
				_puts_error(argv[1]);
				putchar_error('\n');
				putchar_error(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = s_fd;
	}
	populate_env(info);
	hsh(info, argv);
	return (EXIT_SUCCESS);
}
