#include "shell.h"

/**
 * read_buf - reads a buffer from a file descriptor
 * @info: parameter struct for the program
 * @buf_you: buffer to read into
 * @iu: size of buffer
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf_you, size_t *iu)
{
	ssize_t r = 0;

	if (*iu)
	{
		return (0);
	}
	r = read(info->readfd, buf_you, READ_BUF_SIZE);
	if (r >= 0)
	{
		*iu = r;
	}
	return (r);
}
