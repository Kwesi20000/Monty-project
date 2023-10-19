#include "monty.h"
/**
 *f_rotr- function rotates the stack to the bottom
 *@head: stack head
 *@line_num: line_number
 *Return: Nothing
*/
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int line_num)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
