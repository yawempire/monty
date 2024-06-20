#include "monty.h"

/**
  * main - Entry point of the monty code
  * @argc: Argument count
  * @argv: Argument values
  *
  * Return: 0 on success
  */

int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	execute_file(file);
	fclose(file);

	return (0);
}
