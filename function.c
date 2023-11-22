#include "main.h"

/**
 * _print_char - prints character from the corresponding
 * argument from the arguments list
 * @a: list of arguments, va_list
 *
 * Return: the number of printed chars, int
 */
int _print_char(va_list a)
{
	/* Get the character from the arguments list */
	char c = va_arg(a, int);

	/* Write the character to stdout */
	write(1, &c, 1);

	/* Return the number of characters printed */
	return (1);
}

/**
 * _print_mod - prints modular from the corresponding
 * argument from the arguments list
 * @a: list of arguments, va_list
 *
 * Return: the number of printed chars, int
 */
int _print_mod(va_list a)
{
	/* Ignore the arguments list */
	(void)a;

	/* Write the modulus character to stdout */
	write(1, "%", 1);

	/* Return the number of characters printed */
	return (1);
}

/**
 * _print_string - prints character from the corresponding
 * argument from the arguments list
 * @a: list of arguments, va_list
 *
 * Return: the number of printed chars, int
 */
int _print_string(va_list a)
{
	char *str = va_arg(a, char *);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, strlen(str));
	return (strlen(str));
}

/**
 * _print_int - prints integer from the corresponding
 * argument from the arguments list
 * @a: list of arguments, va_list
 *
 * Return: the number of printed chars, int
 */
int _print_int(va_list a)
{

	int n = va_arg(a, int);
	char intStr[] = "           ";
	int i, digit_MAX = 11, duplicate = n, count;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	for (i = 10; n != 0; i--)
	{
		char digit = n % 10;

		if (digit < 0)
		{
			digit = -1 * digit;
		}
		intStr[i] = '0' + digit;
		n = n / 10;
	}
	if (duplicate < 0)
	{
		intStr[i] = '-';
	}
	else
	{
		i++;
	}
	count = digit_MAX - i;
	write(1, &intStr[i], count);
	return (count);
}
