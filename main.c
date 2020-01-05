#include "monty.h"
/**
 * tock - function input
 * @a : function
 * @struct : double poinetr
 *
 * Return : function
 **/
void tock(char *a, stack_t **structu)
{
instruction_t tock[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{NULL, NULL}
};
int i = 0;

while (tock[i].opcode && i <= 4)
{
if (strcmp(tock[i].opcode, a) == 0)
{
tock[i].f(structu, 8);
}
i++;
}
}

/**
  * main - command input
  * @argc: arguments
  * @argv: input
  *
  * Return: Always 0
  **/
int main(int argc, char *argv[])
{
char **a = NULL;
char **b = NULL;
char *c = NULL;

stack_t *stack;
int num = 0;
int i = 0;

a = malloc(sizeof(char *) * 64);
if (a == NULL)
exit(EXIT_FAILURE);
if (argc != 2)
{
fprintf(stderr, "L%s: usage: push integer\n", argv[1]);
exit(EXIT_FAILURE);
}
else
{
c = "\n";
a = get_Tokens(argv[1], c);
c = " ";
while (a != NULL)
{
b = get_Tokens(a[i], c);
num = atoi(b[i + 1]);
tock(b[i], &stack);
i++;
}
}
num = num;
return (0);
}

#include "monty.h"
/**
 * Token - generate Tokens
 * @op : argv[1]
 * @a : since screen
 * Return: TokenT
 **/
char **get_Tokens(char *op, char *a)
{
char **Tok, *aux;
int i = 0;

Tok = malloc(sizeof(char *) * 64);
if (Tok == NULL)
exit(EXIT_FAILURE);
aux = strtok(op, a);
while (aux != NULL)
{
if (*aux != ' ')
Tok[i] = aux;
aux = strtok(NULL, a);
i++;
}
return (Tok);
}
