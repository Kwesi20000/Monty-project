#include "monty.h"
/**
 * f_pop - function prints the top
 * @head: stack head
 * @line_num: line_number
 * Return: Nothing
*/
void f_pop(stack_t **head, unsigned int line_num)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: Can't pop an empty stack\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
