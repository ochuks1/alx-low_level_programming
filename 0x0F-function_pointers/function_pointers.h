#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

/**
 * struct op - Struct op
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
    char *op; // The operator
    int (*f)(int a, int b); // The function associated
} op_t;

/* Function prototypes */
int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
int (*get_op_func(char *s))(int, int);


/* Function prototype for printing a name */
void print_name(char *name, void (*f)(char *));

/* Function that executes a function given as a parameter on each element of an array */
void array_iterator(int *array, size_t size, void (*action)(int));

/* Function that searches for integer */
int int_index(int *array, int size, int (*cmp)(int));

/* Function that selects the correct function to perform the operation asked by the user. You’re not allowed to declare any other function */
int (*get_op_func(char *s))(int, int);

#endif /* FUNCTION_POINTERS_H */
