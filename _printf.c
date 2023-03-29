#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

int identify(char, va_list);
int _printf(const char *format, ...);

/**
 * _printf - recreating printf
 *
 * @format: formattting of output
 *
 * Return: lint
 */

int _printf(const char *format, ...)
{
	int i = 0, len = 0, print_flag = 0, flag = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			len += _putchar(format[i]);
			continue;
		}
		if (format[i + 1] == '%')
		{
			len += _putchar('%');
			i++;
			flag = 1;
			continue;
		}

		if (format[i + 1] == '\0' && format[i] == '%')
			return (-1);
		if (format[i + 1] == '\0')
			return (len);

		print_flag = identify(format[i + 1], args);

		if (print_flag == -1 || print_flag != 0)
			i++;
		if (print_flag > 0)
			len += print_flag;
		if (print_flag == 0 && flag == 0)
		{
			_putchar('%');
			len++;
		}
	}
	va_end(args);
	return (len);
}

/**
 * identify - identify the specifier used after %
 * @ch: char of specifier
 * @args: va_list of variables
 * Return: int / len
 */
int identify(char ch, va_list args)
{
	int i;
	d_type data_type[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"b", print_ui_b},
		{"u", print_unsigned},
		{"x", print_x},
		{"X", print_X},
		{"R", print_rot},
		{NULL, NULL}
		};

	for (i = 0; data_type[i].sp != NULL; i++)
	{
		if (data_type[i].sp[0] == ch)
			return (data_type[i].f(args));
	}
	return (0);
}
