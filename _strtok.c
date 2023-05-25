#include "shell.h"
/**
 * **_strtok - splits a string into words.  line by line
 * @q: the input string
 * @z: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **_strtok(char *q, char *z)
{
int idx1, idx2, idx3, idx4, numwords = 0;
char **arr;
if (q == NULL || q[0] == 0)
return (NULL);
if (!z)
z = " ";
for (idx1 = 0; q[idx1] != '\0'; idx1++)
if (!is_delim(q[idx1], z) && (is_delim(q[idx1 + 1], z) ||
!q[idx1 + 1]))
numwords++;
if (numwords == 0)
return (NULL);
arr = malloc((1 + numwords) *sizeof(char *));
if (!arr)
return (NULL);
for (idx1 = 0, idx2 = 0; idx2 < numwords; idx2++)
{
while (is_delim(q[idx1], z))
	idx1++;
idx3 = 0;
while (!is_delim(q[idx1 + idx3], z) && q[idx1 + idx3])
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
arr[idx2][idx4] = q[idx1++];
arr[idx2][idx4] = 0;
}
arr[idx2] = NULL;
return (arr);
}
