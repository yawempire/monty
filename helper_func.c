#include "monty.h"

/**
  * len_of_stack - returns the number of elements in stack
  * @head: current position of stack
  *
  * Return: the number of nodes
  */

int len_of_stack(const stack_t *head)
{
	int node_count = 0;

	while (head != NULL)
	{
		node_count++; /* increment the node count when head is not NULL */
		head = head->next;
	}

	/* Return the number of nodes */
	return (node_count);
}

/**
  * free_array - Frees the array
  * @tokens: The various elements in the array
  */

void free_array(char **tokens)
{
	int a;

	if (tokens == NULL)
		return;

	for (a = 0; tokens[a] != NULL; a++)
		free(tokens[a]), tokens[a] = NULL;

	free(tokens), tokens = NULL;
}

/**
  * is_valid_integer - Checks if the argument is a valid integer
  * @str: String argument
  *
  * Return: 1 if valid, 0 otherwise
  */

int is_valid_integer(char *str)
{
	if (*str == '-')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);

		str++;
	}

	return (1);
}

/**
  * total_tokens - Count the number of tokens
  * @line: line to be tokenized
  *
  * Return: the number of tokens
  */

int total_tokens(char *line)
{
	char *line_cpy = NULL, *token;
	int num_token = 0;

	if (!line)
		return (0);

	line_cpy = strdup(line);
	token = strtok(line_cpy, " \t\n");

	if (token == NULL)
	{
		free(line), line = NULL;
		free(line_cpy), line_cpy = NULL;
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	while (token)
	{
		num_token++;
		token = strtok(NULL, " \t\n");
	}

	free(line_cpy);
	return (num_token);
}

/**
  * tokenize - Function to help tokenize the input
  * @buf: input to be tokenized
  *
  * Return: Array of tokens
  */

char **tokenize(char *buf)
{
	char *token, **tokens;
	int i = 0, num_tokens;

	num_tokens = total_tokens(buf);

	tokens = malloc((sizeof(char *) * (num_tokens + 1)));

	if (tokens == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(buf, " \t\n");
	while (token)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, " \t\n");
	}

	tokens[i] = NULL;

	return (tokens);
}
