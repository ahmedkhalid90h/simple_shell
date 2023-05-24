#include "shell.h"

/**
 * set_info_initializes - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void set_info_initializes(info_t *info, char **av)
{
    int i = 0;

    info->filename = av[0];
    if (info->arg)
    {
        info->argv = strtok(info->arg, " \t");  /* up to _strtok */
        if (!info->argv)
        {
            info->argv = malloc(sizeof(char *) * 2);
            if (info->argv)
            {
                info->argv[0] = strdup(info->arg); /* up to _strdup */
                info->argv[1] = NULL;
            }
        }

        while (info->argv && info->argv[i])
        {
            /* TODO: replace aliases */   /* up */
            /* TODO: replace variables */  /* up */
            i++;
        }

        info->argc = i;
    }
}
