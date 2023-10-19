#include "monty.h"
/**
 * f_push - function adds node to the stack
 * @head: stack head
 * @line_num: line_number
 * Return: Nothing
*/
void f_push(stack_t **head, unsigned int line_num)
{
	int n, a = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			a++;
		for (; bus.arg[a] != '\0'; a++)
		{
			if (bus.arg[a] > 57 || bus.arg[a] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_num);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}
