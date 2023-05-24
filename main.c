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
	unsigned int line;
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
	for (line = 1; ; line++)
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
				fprintf(stderr, "L%d: unknown instruction %s\n", line, args[0]);
				free_args(args);
				break;
			}
		}
	}
	free_stack(&head);
	close(fd);
	if (op == -1)
		exit(EXIT_FAILURE);
	return (0);
}
