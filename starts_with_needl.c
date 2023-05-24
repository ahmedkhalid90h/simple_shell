#include "shell.h"

/**
 * starts_with_needl - checks if needle_frist_dt starts with haystack_dt
 * @haystack_dt: string to search
 * @needle_frist_dt: the substring to find
 *
 * Return: address of next char of haystack_dt or NULL
 */

char *starts_with_needl(const char *haystack_dt, const char *needle_frist_dt)
{
	int i;
	for (i = 0; needle_frist_dt[i] != '\0'; i++)
		if (needle_frist_dt[i] != haystack_dt[i])
			return NULL;
	return (char *)haystack_dt;
}
