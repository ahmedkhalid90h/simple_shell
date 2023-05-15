#include "shell.h"

/**
 * find_commd - finds a command in PATH file path
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void find_commd(info_t *info)
{
    char *path = NULL;
    int counter = 0, k = 0;

    info->path_f = info->argv_x[0];
    if (info->linecount_flag == 1)
    {
        info->line_count_++;
        info->linecount_flag = 0;
    }

    while (info->arg_c[counter])
    {
        if (!is_delimeter_char(info->arg_c[counter], " \t\n"))
            k++;
        counter++;
    }
    if (!k)
        return;

    path = find_path_f(info, _getenv(info, "PATH="), info->argv_x[0]); 
    if (path)
    {
        info->path_f = path;
        create_child_fork(info);
    }
    else
    {
        if ((interactive_mode(info) || _getenv(info, "PATH=") /* up to __getenv */
            || info->argv_x[0][0] == '/') && is_cmd_(info, info->argv_x[0]))
            create_child_fork(info);
        else if (*(info->arg_c) != '\n')
        {
            info->status = 127;
            print_err(info, "not found\n");
        }
    }
}
