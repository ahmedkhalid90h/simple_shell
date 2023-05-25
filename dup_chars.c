#include "shell.h"

/**
 * dup_ch - duplicates characters or strings from a buffer
 * @path_str: the PATH string to duplicate from
 * @start_idx: starting index of the string to duplicate
 * @stop_idx: stopping index of the string to duplicate
 *
 * Return: pointer to new buffer
 */
char *dup_ch(char *path_str, int start_idx, int stop_idx)
{
static char buf[1024];
int k = 0;
int i = start_idx;

while (i < stop_idx)
{
if (path_str[i] != ':')
{
buf[k++] = path_str[i];
}
i++;
}
buf[k] = 0;
return (buf);
}
