#include "shell.h"
/**
 * _getline - gets the next line of the input from the STDIN and stores it
 * @info: parameter struct
 * @ptq: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptq, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t i, len;
size_t k;
ssize_t r = 0, s = 0;
char *p = NULL, *new_p = NULL, *c;

p = *ptq;
if (p && length)
{
s = *length;
}
if (i == len)
{
i = len = 0;
}
r = read_buf(info, buf, &len);
if (r == -1 || (r == 0 && len == 0))
{
return (-1);
}
c = _strchr(buf + i, '\n');
k = c ? 1 + (unsigned int)(c - buf) : len;
new_p = _realloc(p, s, s ? s + k : k + 1);
if (!new_p) /* MALLOC FAILURE! */
{
return (p ? free(p), -1 : -1);
}

if (s)
{
_strncat(new_p, buf + i, k - i);
}
else
{
_strncpy(new_p, buf + i, k - i + 1);
}
s += k - i;
i = k;
p = new_p;
if (length)
{
*length = s;
}
*ptq = p;
return (s);
}
/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@cdc: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *sq, char cdc)
{
do {
if (*sq == cdc)
return (sq);
} while (*sq++ != '\0');

return (NULL);
}
