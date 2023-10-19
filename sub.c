#include "monty.h"
/**
 *f_sub - sustration function
 *@head: stack head
 *@line_num: the line_number
 *Return: Nothing
*/
void f_sub(stack_t **head, unsigned int line_num)
{
	stack_t *a;
	int sus, nodes;

	a = *head;
	for (nodes = 0; a != NULL; nodes++)
		a = a->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	a = *head;
	sus = a->next->n - a->n;
	a->next->n = sus;
	*head = a->next;
	free(a);
}
