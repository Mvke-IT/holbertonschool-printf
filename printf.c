#include "main.h"
#include <stddef.h>
#include <stdarg.h>
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - printf func
 * @format: format
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int buff_ind;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];

			if (buff_ind == BUFF_SIZE)

				print_buffer(buffer, &buff_ind);

			printed_chars++;
		}

			{
			printed = handle_print(format, &i);

			if (printed == -1)
				return (-1);

			printed_chars += printed;
			}
		}
	print_buffer(buffer, &buff_ind);

	va_end(list);
	return (printed_chars);
	
}
/**
 * print_buffer - prints the context if the buffers if they exist
 * @buffer: array
 * @buff_ind: index to add next char
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)

		write(1, &buffer[0], *buff_ind);

	buff_ind = 0;
}
