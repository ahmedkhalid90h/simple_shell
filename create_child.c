#include "shell.h"

/**
 * create_child - forks a an exec thread to run cmd in child process
 * @info: the parameter & return info struct for shell
 *
 * Return: void
 */
void create_child(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				{
					exit(126);
				}
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				{
					print_error(info, "Permission denied\n");
				}
		}
	}
}
