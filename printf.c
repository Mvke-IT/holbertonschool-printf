#include "main.h"

/**
 * _printf - takes a string and args of each '%'
 * and prints them
 * @format: initial string
 * @...: variable list of arguments
 * Return: number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list a;
	int count = 0, j, i;
	_printf_functions types[] = {{"c", _print_char},
		{"s", _print_string},
		{"i", _print_int},
		{"d", _print_int},
		{"%", _print_mod},
		{NULL, NULL}};

/* Check if the format string is NULL. If it is, return -1. */
if (format == NULL)
{
  return (-1);
}

/* Initialize the variable argument list. */
va_start(a, format);

/* Iterate through the characters in the format string. */
for (i = 0; format[i]; i++)
{

  /* If the current character is a '%', then skip any whitespace characters
     and then check if the next character is a valid conversion specifier. */
  if (format[i] == '%')
  {

    /* Skip any whitespace characters after the '%' character. */
    while (format[++i] == ' ')
      ;

    /* Iterate through the _printf_functions array and check if the current
       character is a valid conversion specifier. If it is, then call the
       corresponding function to print the argument. */
    for (j = 0; types[j].convertion_specifier != NULL; j++)
    {

      /* Check if the current character matches the conversion specifier of
         the current function in the array. */
      if (format[i] == *types[j].convertion_specifier)
      {

        /* Call the function to print the argument. */
        count += types[j].function(a);
        break;
      }
    }

    /* If the current character is not a valid conversion specifier, then
       simply print it to stdout. */
    if (types[j].convertion_specifier == NULL)
    {

      /* Write the current character to stdout. */
      write(1, &format[i], 1);

      /* Increment the count of characters printed. */
      count++;
    }
  }
  /* If the current character is not a '%', then simply print it to stdout. */
  else
  {
    /* Write the current character to stdout. */
    write(1, &format[i], 1);

    /* Increment the count of characters printed. */
    count++;
  }
}

/* Close the variable argument list. */
va_end(a);

/* Return the number of characters printed. */
return (count);

}
