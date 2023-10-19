#include "monty.h"
/**
 * f_pall - function prints the stack
 * @head: stack head
 * @line_num: line number
 * Return: Nothing
*/
void f_pall(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	(void)line_num;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
