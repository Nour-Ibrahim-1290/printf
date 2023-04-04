 _Printf Customization
=====
function implementation

The _printf function is a custom implementation of the standard C library function printf. It allows you to format and output text to the console or other output streams.

This program implements a custom printf function that supports the following conversion specifiers:
**%c** : prints a single character
**%s** : prints a null-terminated string
**%d**, %i, %u, %o, %x, %X : prints a signed/unsigned integer in decimal, octal, or hexadecimal format
**%p** : prints a pointer address
**%S** : prints a string with non-printable characters represented in the format \xXX (where XX is the ASCII code value in hexadecimal, always two characters in uppercase)
