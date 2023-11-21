#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * Return: 1 or 2
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[])
{
	int i, unknown_len = 0, printed_chars = -1;


