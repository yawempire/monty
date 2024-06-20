#include "monty.h"

/**
  * free_close_exit - Does the work of free line, stack and close,exit
  * @line: The particular line
  * @stack: The stack we're working with
  * @file: The file which is being read
  */

void free_close_exit(char *line, stack_t *stack, FILE *file)
{
	free(line);
	free_stack(&stack);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
  * execute_file - Executes operations on the file
  * @file: The file to be operated on
  */

void execute_file(FILE *file)
{
	size_t count = 0;
	char *buf = NULL, *value_of_str;
	unsigned int line_num = 0;
	char **tokens;
	stack_t *stack = NULL;

	while (getline(&buf, &count, file) != -1)
	{
		line_num++;
		if (!buf)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_close_exit(buf, stack, file);
		}
		if (buf[0] == '#')
			continue;
		tokens = tokenize(buf);
		if (tokens == NULL)
			continue;
		if (strcmp(tokens[0], "push") == 0)
		{
			value_of_str = tokens[1];
			if (value_of_str == NULL || !is_valid_integer(value_of_str))
			{
				fflush(stdout);
				fprintf(stderr, "L%d: usage: push integer\n", line_num);
				free(value_of_str);
				free_close_exit(buf, stack, file);
			}
			push_func(&stack, line_num, atoi(value_of_str));
		}
		else if (choose_opcode(tokens, &stack, line_num) == 1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, tokens[0]);
			free_close_exit(buf, stack, file);
		}
		free_array(tokens);
	}
	free(buf);
	free_stack(&stack);
}
