#include "main.h"
/**
 * _printf - takes a string and arguments from each '%'
 * @format: initial string
 * @...: variable list of args
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list a;
	int count = 0, j, i;
	_printf_functions types[] = {{"c", _printf_char},
		{"s", _print_string}, {"i", _printf_char},
		{"d", _print_int}, {"%", _print_mod},
		{NULL, NULL}};
	if (format == NULL)
	{
		return (-1);
	}
	va_start(a, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			while (format[++i] == ' ')
			;
			for (j = 0; types[j].convertion_specifier != NULL; j++)
			{
				if (format[i] == *types[j].convertion_specifier)
				{
					count += types[j].function(a);
					break;
				}
			}
			if (types[j].convertion_specifier == NULL)
			{
				write(1, &format[i], 1);
				count++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(a);
	return (count);
}
