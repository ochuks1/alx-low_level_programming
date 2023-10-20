#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - print name using pointer to function
 * @name: string to add
 * @f: pointer to function
 * Return: nothing
 **/
void print_name(char *name, void (*f)(char *))
{
if (name == NULL || f == NULL)
return;

f(name);
}

/**
 * print_name_as_is - Prints a name as is.
 * @name: Name of the person.
 */
void print_name_as_is(char *name)
{
    printf("Hello, my name is %s\n", name);
}
