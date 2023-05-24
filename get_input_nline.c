#include "shell.h"

/**
 * get_input_nline - gets a line minus the newline. bytes
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input_nline(info_t *info)
{
    static char *chain_buf;
    static size_t chain_buf_pos, current_pos, chain_buf_len;
    ssize_t bytes_read = 0;
    char **current_cmd_p = &(info->arg_c), *current_pos_p;

    putchar(BUF_FLUSH); /* up to _putchar*/
    bytes_read = input_buf(info, &chain_buf, &chain_buf_len);
    if (bytes_read == -1) /* EOF */
        return (-1);
    if (chain_buf_len) /* we have commands left in the chain buffer */
    {
        current_pos = chain_buf_pos; /* init new iterator to current chain_buf_pos */
        current_pos_p = chain_buf + chain_buf_pos; /* get pointer for return */

        check_next_f(info, chain_buf, &current_pos, chain_buf_pos, chain_buf_len);
        for (; current_pos < chain_buf_len; current_pos++) /* iterate to semicolon or end */
        {
            if (is_next_c(info, chain_buf, &current_pos))
                break;
        }

        chain_buf_pos = current_pos + 1; /* increment past nulled ';'' */
        if (chain_buf_pos >= chain_buf_len) /* reached end of buffer? */
        {
            chain_buf_pos = chain_buf_len = 0; /* reset position and length */
            info->cmd_buf_type = NORM;
        }

        *current_cmd_p = current_pos_p; /* pass back pointer to current command position */
        return (strlen(current_pos_p)); /* up to _strlen */
    }

    *current_cmd_p = chain_buf; /* else not a chain, pass back buffer from _getline() */
    return (bytes_read); /* return length of buffer from _getline() */
}