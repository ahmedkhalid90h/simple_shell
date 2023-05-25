#include "shell.h"

/**
 * cre_ch - forks a an exec thread to run cmd in child process
 * @info: the parameter & return info struct for shell
 *
 * Return: void
 */
void cre_ch(info_t *info)
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
			info_free(info, 1);
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
				error_print(info, "Permission denied\n");
			}
		}
	}
}
