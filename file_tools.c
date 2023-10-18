#include "monty.h"

/**
 * open_file - This function opens a file
 * @file_name: the file name
 * Return: Returns nothing
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{
		error(2, file_name);
	}

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - Function reads a file
 * @fd: The pointer to file descriptor
 * Return: Nothing
 */

void read_file(FILE *fd)
{
	int line_num, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buffer, &len, fd) != -1; line_num++)
	{
		format = parse_line(buffer, line_num, format);
	}
	free(buffer);
}


/**
 * parse_line - Function separates each line into tokens to determine
 * which function to call
 * @buffer: The line from the file
 * @line_num: The line number
 * @format:  The storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if it is a queue.
 */

int parse_line(char *buffer, int line_num, int format)
{
	char *opcode, *value;
	const char *delimeter = "\n ";

	if (buffer == NULL)
		error(4);

	opcode = strtok(buffer, delimeter);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delimeter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, value, line_num, format);
	return (format);
}

/**
 * find_function - Function finds the appropriate function for the opcode
 * @opcode: The opcode
 * @value: The argument of opcode
 * @format:  The storage format. If 0 Nodes will be entered as a stack.
 * @line_num: The line number
 * if 1 nodes will be entered as a queue.
 * Return: Nothing
 */
void find_function(char *opcode, char *value, int line_num, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_character},
		{"pstr", print_string},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_function(func_list[i].f, opcode, value, line_num, format);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		error(3, line_num, opcode);
	}
}


/**
 * call_function - Function calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line number for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_function(op_func function, char *op, char *val, int ln, int format)
{
	stack_t *head = NULL;
	stack_t *node;
	int flag;
	int j;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error(5, ln);
		for (j = 0; val[j] != '\0'; j++)
		{
			if (isdigit(val[j]) == 0)
				error(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			function(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		function(&head, ln);
}
