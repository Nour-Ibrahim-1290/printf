#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct d_type - structure of function pointers
 * @sp: specifier char to match function with
 * @f: function to invoke
 */
typedef struct d_type
{
	char *sp;
	int (*f)(va_list);
} d_type;

int _printf(const char *format, ...);
int print_char(va_list);
int print_str(va_list);
int _strlen(char *);
int _putchar(char);
int print_int(va_list);
void to_binary(unsigned int, int*);
int print_ui_b(va_list);
int print_unsigned(va_list);
int print_X(va_list);
int print_x(va_list);
int print_rot(va_list);
#endif
