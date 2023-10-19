#include "monty.h"
/**
* f_stack - function frees a doubly linked list
* @head: head of the stack
* Return: Nothing
*/
void f_stack(stack_t *head)
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
