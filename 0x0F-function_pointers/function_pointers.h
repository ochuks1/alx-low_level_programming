#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

/* Function prototype for printing a name */
void print_name(char *name, void (*f)(char *));

/* Function that executes a function given as a parameter on each element of an array */
void array_iterator(int *array, size_t size, void (*action)(int));

/* Function that searches for integer */
int int_index(int *array, int size, int (*cmp)(int));

/* Function that selects the correct function to perform the operation asked by the user. You’re not allowed to declare any other function */
int (*get_op_func(char *s))(int, int);

#endif /* FUNCTION_POINTERS_H */
