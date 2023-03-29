#include "main.h"
#include <stdio.h>

int print_unsigned(va_list);
int print_rot(va_list);
void to_binary(unsigned int, int *);
int print_ui_b(va_list);

/**
 * print_unsigned - function that prints unsigned int
 * @args: unsigned int
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
 * print_rot - encodes a string into rot13
 * @args: string to convert
 * Return: size of the output text
 */


int print_rot(va_list args)
{
	int j, i, count = 0;
	char *r;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";

	r = va_arg(args, char *);
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

/**
 * to_binary - convert unsigned int into binary and print it
 * @n: unsigned int to convert into binary
 * @len: pointer to counter for printing length
 * Return: void.
 */
void to_binary(unsigned int n, int *len)
{
	if (n > 1)
	{
		*len += 1;
		to_binary(n >> 1, len);
	}
	_putchar((n & 1) + '0');
}


/**
 * print_ui_b - print unsigned int in binary format
 * @args: va_list to get args from
 * Return: length of printed binary
 */
int print_ui_b(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int len;
	int *p;

	p = &len;

	to_binary(n, p);

	p = NULL;
	return (len);
}
