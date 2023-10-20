#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints the elements of a list_t list and counts the nodes.
 * @h: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
    size_t count = 0;  /* Initialize a counter for nodes */

    while (h != NULL)
    {
        if (h->str == NULL)
            printf("[0] (nil)\n");  /* Print if the string is NULL */
        else
            printf("[%lu] %s\n", h->len, h->str);  /* Print the string length and content */

        h = h->next;  /* Move to the next node */
        count++;  /* Increment the node counter */
    }

    return count;  /* Return the total number of nodes */
}
