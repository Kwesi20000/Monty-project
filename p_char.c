#include "monty.h"
/**
 * f_pcharacter - function prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @line_num: line_number
 * Return: Nothing
*/
void f_pcharacter(stack_t **head, unsigned int line_num)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
