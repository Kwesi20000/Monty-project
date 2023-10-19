#include "monty.h"
/**
* free_stack - function frees a doubly linked list
* @head: head of the stack
* Return: Nothing
*/
void free_stack(stack_t *head)
{
	stack_t *a;

	a = head;
	while (head)
	{
		a = head->next;
		free(head);
		head = a;
	}
}
