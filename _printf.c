#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - recreating printf
 *
 * @format: formattting of output
 *
 * Return: lint
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, len = 0, tmp = 0;
	va_list args;
	d_type data_type[] = {
		{'c', print_char},
		{'s', print_str},
		{'d', print_int},
		{'i', print_dec}
		};

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			len += _putchar(format[i]);
		else
		{
			i++;
			j = 0;
			while (j < 4 && format[i] != data_type[j].sp)
				j++;
			if (j < 4)
			{
				tmp = data_type[j].f(args);
				if (tmp == -1)
					len++;
				else
					len += tmp;
			}
			else
				_putchar('%');
		}
		i++;
	}
	va_end(args);
	return (len);
}
