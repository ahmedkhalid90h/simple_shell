#include "shell.h"

/**
 * **_strtok - splits a string into words. Repeat delimiters are ignored line by line
 * @input_str: the input string
 * @delim: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **_strtok(char *input_str, char *delim)
{
    int idx1, idx2, idx3, idx4, numwords = 0;
    char **arr;

    if (input_str == NULL || input_str[0] == 0)
        return (NULL);
    if (!delim)
        delim = " ";
    for (idx1 = 0; input_str[idx1] != '\0'; idx1++)
        if (!is_delimeter_char(input_str[idx1], delim) && (is_delimeter_char(input_str[idx1 + 1], delim) || !input_str[idx1 + 1]))
            numwords++;

    if (numwords == 0)
        return (NULL);
    arr = malloc((1 + numwords) * sizeof(char *));
    if (!arr)
        return (NULL);
    for (idx1 = 0, idx2 = 0; idx2 < numwords; idx2++)
    {
        while (is_delimeter_char(input_str[idx1], delim))
            idx1++;
        idx3 = 0;
        while (!is_delimeter_char(input_str[idx1 + idx3], delim) && input_str[idx1 + idx3])
            idx3++;
        arr[idx2] = malloc((idx3 + 1) * sizeof(char));
        if (!arr[idx2])
        {
            for (idx3 = 0; idx3 < idx2; idx3++)
                free(arr[idx3]);
            free(arr);
            return (NULL);
        }
        for (idx4 = 0; idx4 < idx3; idx4++)
            arr[idx2][idx4] = input_str[idx1++];
        arr[idx2][idx4] = 0;
    }
    arr[idx2] = NULL;
    return (arr);
}
