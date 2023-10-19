#include "monty.h"
/**
 * f_pstring - funtion prints the string starting at the top of the stack
 * followed by a new
 * @head: stack head
 * @line_num: line_number
 * Return: Nothing.
*/
void f_pstring(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	(void)line_num;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
