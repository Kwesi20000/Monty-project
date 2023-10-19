#include "monty.h"
/**
 *f_rotl- rotates the stack to the top
 *@head: stack head
 *@line_num: line_number
 *Return: Nothing
*/
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int line_num)
{
	stack_t *temp = *head, *a;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	a = (*head)->next;
	a->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = a;
}
