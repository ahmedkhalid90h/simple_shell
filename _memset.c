#include "shell.h"

/**
 **_mem_cut - fills memory witjesth a constant byte
 *@s: the pointer to the the the memory area
 *@b_q: the byte to fill the  *s with
 *@n: the amount of the th  bytes to be filled
 *Return: (s) a pointer  bythe theto the memory area s
 */
char *_mem_cut(char *s, char b_q, unsigned int n) /* not file  _mem_cut*/
{
	unsigned int iD;

	for (iD = 0; iD < n; iD++)
		s[iD] = b_q;
	return (s);
}
