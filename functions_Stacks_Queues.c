#include "monty.h"
/**
 * push - adition new node
 * @stack: new node
 * @h: init double linked lists
 *
 * Return: new element or NULL
**/
void push(stack_t **stack, unsigned int h)
{
stack_t *new;

new = malloc(sizeof(new));
if (new == NULL)
exit(EXIT_FAILURE);
if (*stack == NULL)
{
*stack = new;
(*stack)->prev = NULL;
(*stack)->next = NULL;
(*stack)->n = h;
}
else
{
new->next = *stack;
(*stack)->prev = new;
new->prev = NULL;
new->n = h;
*stack = new;
}
}

/**
 * pall - print d_listint
 * @h: double listen
 * @stack: pointer
 *
 */
void pall(stack_t **stack, unsigned int h)
{
size_t a = 0;
h = h;
if (stack == NULL)
exit(EXIT_SUCCESS);
for (a = 0; *stack != NULL; a++)
{
printf("%d\n", (*stack)->n);
*stack = (*stack)->next;
}
}

/**
 * pint - print date
 * @stack : pointer
 * @h: int
 *
 */

void pint(stack_t **stack, unsigned int h)
{
if (!stack)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", h);
exit(EXIT_FAILURE);
}
else
printf("%d\n", (*stack)->n);
}

/**
 * pop - Function that remove
 * @stack : pointer of input
 * @h : int of input
 *
 */
void pop(stack_t **stack, unsigned int h)
{
stack_t *new;

if (stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", h);
exit(EXIT_FAILURE);
}
else
{
new = *stack;
*stack = new->next;
new->next = NULL;
(*stack)->prev = NULL;
free(new);
}
}

/**
 * swap - print date
 * @h : int
 * @stack : pointer
 */

void swap(stack_t **stack, unsigned int h)
{
stack_t *new = NULL;
int a = 0, i = 0;

while ((*stack)->next != NULL)
{
*stack = (*stack)->next;
i++;
}
if (i < 2)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", h);
exit(EXIT_FAILURE);
}
else
{
new = new->next;
a = new->n;
new->n = (*stack)->n;
(*stack)->n = a;
}
}
