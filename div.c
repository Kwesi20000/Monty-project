#include "monty.h"
/**
 * f_div - function divides the top two elements of the stack.
 * @head: stack head
 * @line_num: line_number
 * Return: Nothing
*/
void f_div(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	int len = 0, a;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	a = h->next->n / h->n;
	h->next->n = a;
	*head = h->next;
	free(h);
}