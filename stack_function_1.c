#include "monty.h"


/**
 * add_to_stack - This function adds a node to the stack.
 * @new_node: The pointer to the new node.
 * @ln: The integer representing the line number of of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * print_stack - Function prints a node to the stack.
 * @stack: The pointer to a pointer pointing to top node of the stack.
 * @line_num: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop_top - Function adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Integer representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_error(7, line_num);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * print_top - Function prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Integer representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		more_error(6, line_num);
	}
	printf("%d\n", (*stack)->n);
}
