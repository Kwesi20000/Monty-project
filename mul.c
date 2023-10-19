include "monty.h"
/**
 * f_mul - function multiplies the top two elements of the stack.
 * @head: stack head
 * @line_num: line_number
 * Return: Nothing
*/
void f_mul(stack_t **head, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = a;
	*head = h->next;
	free(h);
}
