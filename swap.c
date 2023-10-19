#include "monty.h"
/**
 * f_swap - Function adds the top two elements of the stack.
 * @head: stack head
 * @line_num: line number
 * Return: Nothing
*/
void f_swap(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	int len = 0, i;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = i;
}
