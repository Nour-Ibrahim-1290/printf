#include "main.h"
#include <stdio.h>

int print_unsigned(va_list);
int print_rot(va_list);

/**
 * print_unsign - function that prints unsigned int
 * @u: unsigned int
 * Return: size of the output chars
 */
int print_unsigned(va_list args)
{
	unsigned int len, po, j, digit, n, num;
	int count = 0;

	n = va_arg(args, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		po = 1;
		for (j = 1; j <= len - 1; j++)
			po *= 10;
		for (j = 1; j <= len; j++)
		{
			digit = n / po;
			_putchar(digit + '0');
			count++;
			n -= digit * po;
			po /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}

/**
 * print_rot13 - encodes a string into rot13
 * @R: string to convert
 * Return: size of the output text
 */


int print_rot(va_list R)
{
	int j, i, count = 0;
	char *r;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";

	r = va_arg(R, char *);
	if (r == NULL)
		r = "(null)";
	for (j = 0; r[j] != '\0'; j++)
	{
		for (i = 0; input[i] != '\0'; i++)
		{
			if (r[j] == input[i])
			{
				_putchar(output[i]);
				count++;
				break;
			}
		}
	}
	return (count);
}
