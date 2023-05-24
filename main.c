#include "monty.h"

/**
 * main - main
 * @argc: argument count
 * @argv: argument vector
 * )
 * Return: 0
 */
int main(int argc, char **argv)
{
	int fd, op = 0;
	ssize_t check, cmp = -1;
	unsigned int line = 1;
	char *buf;
	stack_t *head = NULL;

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 19);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		check = get_in(&buf, fd);
		if (check == cmp)
			break;
		args = NULL;
		set_args(buf);
		if (args != NULL)
		{
			op = handle_op(&head, line);
			if (op == -1)
			{
				fprintf(stderr, "L%d: unknown instruction%s\n", line, args[0]);
				break;
			}
		}
		line++;
	}
	free_stack(&head);
	if (op == -1)
		exit(EXIT_FAILURE);
	return (0);
}
