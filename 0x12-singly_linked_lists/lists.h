#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/* Struct for a singly linked list node */
typedef struct list_s
{
    char *str;           /* String data */
    size_t len;           /* Length of the string */
    struct list_s *next; /* Pointer to the next node */
} list_t;

/* Function prototype for printing and counting list elements */
size_t print_list(const list_t *h);

/* Function  that prints all the elements of a list_t list */
size_t print_list(const list_t *h);

/* Function prototype to return the number of elements in the list */
size_t list_len(const list_t *h);

/* Function prototype to add a new node at the beginning of the list */
list_t *add_node(list_t **head, const char *str);

/* Function prototype to add a new node at the end of the list */
list_t *add_node_end(list_t **head, const char *str);

/* Function prototype that frees a list_t list */
void free_list(list_t *head);

/* Function prototype to free a list */
void free_list(list_t *head);

/* Function prototype to print a character */
int _putchar(char c);

#endif /* LISTS_H */
