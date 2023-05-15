#include "shell.h"

/**
 * dupl_chars - duplicates characters or strings
 * @path_str: the PATH string
 * @start_idx: starting index
 * @stop_idx: stopping index
 *
 * Return: pointer to new buffer
 */
char *dupl_chars(char *path_str, int start_idx, int stop_idx)
{
    static char buf[1024];
    int k = 0;
    int i = start_idx;

    while (i < stop_idx) {
        if (path_str[i] != ':')
            buf[k++] = path_str[i];
        i++;
    }
    buf[k] = '\0';
    return buf;
}
