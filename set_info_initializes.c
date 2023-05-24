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
    if (info->arg_c)
    {
        info->argv_x = strtok(info->arg_c, " \t");  /* up to _strtok */
        if (!info->argv_x)
        {
            info->argv_x = malloc(sizeof(char *) * 2);
            if (info->argv_x)
            {
                info->argv_x[0] = strdup(info->arg_c); /* up to _strdup */
                info->argv_x[1] = NULL;
            }
        }

        while (info->argv_x && info->argv_x[i])
        {
            /* TODO: replace aliases */   /* up */
            /* TODO: replace variables */  /* up */
            i++;
        }

        info->argc = i;
    }
}
