#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - Prints anything based on the format.
 * @format: A format string specifying the types of arguments.
 * @...: The arguments to be printed.
 */
void print_all(const char * const format, ...)
{
va_list args;
int i = 0;
char *str;
char separator = '\0';

va_start(args, format);
while (format && format[i])
{
if (i > 0)
separator = ',';

switch (format[i])
{
case 'c':
printf("%c", va_arg(args, int));
break;
case 'i':
printf("%d", va_arg(args, int));
break;
case 'f':
printf("%f", (float)va_arg(args, double));
break;
case 's':
str = va_arg(args, char *);
if (!str)
str = "(nil)";
printf("%s", str);
break;
default:
i++;
continue;
}
printf("%c", separator);  /* Print separator after each argument */
i++;
}
va_end(args);

printf("\n");
}
