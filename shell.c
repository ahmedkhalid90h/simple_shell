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

	populate_env(info);
	hsh(info, argv);
	return (EXIT_SUCCESS);
}
