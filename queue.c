#include "monty.h"
/**
 * f_queue - Function prints the top
 * @head: stack head
 * @line_num: line_number
 * Return: Nothing
*/
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)line_num;
	bus.lifi = 1;
}

/**
 * add_queue - function adds node to the tail stack
 * @n: new_value
 * @head: the head of the stack
 * Return: Nothing
*/
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *a;

	a = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (a)
	{
		while (a->next)
			a = a->next;
	}
	if (!a)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		a->next = new_node;
		new_node->prev = a;
	}
}
