#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/* Function that returns the sum of all its parameters */
int sum_them_all(const unsigned int n, ...);

/* Function that prints numbers, followed by a new line */
void print_numbers(const char *separator, const unsigned int n, ...);

/* Function that prints strings, followed by a new line. */
void print_strings(const char *separator, const unsigned int n, ...);

/* Function that prints anything */
void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNCTIONS_H */
