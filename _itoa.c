#include "shell.h"

/**
 * _itoa - converts a number to a string
 * @number: number
 * @base_s: base
 * @flag: argument flags
 *
 * Return: string
 */
char *_itoa(long int number, int base_s, int flag)
{
	static char *arr;
	static char buffer[50];
	char sign_check = 0;
	char *ptr_add;
	unsigned long n = number;


	if (!(flag & CONVERT_UNSIGNED) && number < 0)
	{
		n = -number;
		sign_check = '-';


	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr_add = &buffer[49];
	*ptr_add = '\0';


	do	{
		*--ptr_add = arr[n % base_s];
		n /= base_s;
	} while (n != 0);


	if (sign_check)
		*--ptr_add = sign_check;
	return (ptr_add);
}
