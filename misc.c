#include "monty.h"

/**
 * free_stack - frees the stack
 * @head: the first node
 */
void free_stack(stack_t **head)
{
	stack_t *current = *head;

	while (current)
	{
		current = current->next;
		free(*head);
		*head = current;
	}
}

/**
 * get_in - gets lines
 * @buffer: buffer to hold line
 * @fd: file descriptor
 * )
 * Return: -1 if fail
 */
ssize_t get_in(char **buffer, int fd)
{
	ssize_t check, cmp = -1;
	size_t size = 0;
	char *buf = NULL;

	check = _getline(&buf, &size, fd);
	if (check != cmp)
		*buffer = buf;
	return (check);
}

/**
 * set_args - sets arguments
 * @buf: buffer holding opcode
 * )
 * Return: 0 or -1
 */
int set_args(char *buf)
{
	int i = 0, j = 2;
	char *hold = NULL;

	for (i = 0; (buf[i] != '\0' && buf[i] != '#'); i++)
	{
		if (buf[i] == ' ')
			continue;
		if (args == NULL)
			args = malloc(sizeof(char *) * 2);
		else
			args = _realloc(args, (sizeof(char *) * (j - 1)), (sizeof(char *) * j));
		if (args == NULL)
		{
			free(buf);
			fprintf(stderr, "Error: malloc failed\n");
			return (0);
		}
		while ((buf[i] != ' ') && (buf[i] != '\0' && buf[i] != '#'))
		{
			if (hold == NULL)
				hold = _strcatint(_strdup(""), buf[i]);
			else
				hold = _strcatint(hold, buf[i]);
			i++;
		}
		if (hold != NULL)
		{
			args[j - 2] = _strdup(hold);
			free(hold);
			hold = NULL;
			j++;
		}
		if (buf[i] == '\0')
			break;
	}
	free(buf);
	if (args == NULL)
		return (0);
	args[j - 2] = NULL;
	return (0);
}

/**
 * handle_op - gets command for opcode
 * @head: pointer to stack
 * @line: current line
 * )
 * Return: 0 or -1
 */
int handle_op(stack_t **head, unsigned int line)
{
	instruction_t in[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add}, {"nop", _nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr}, {NULL, NULL}
	};
	int i;
	static int q;

	if ((line == 1) && (_strcmp("queue", args[0]) != 0))
		q = 0;
	if (_strcmp("queue", args[0]) == 0)
	{
		free_args(args);
		q = 1;
		return (0);
	}
	if (_strcmp("stack", args[0]) == 0)
	{
		free_args(args);
		q = 0;
		return (0);
	}
	for (i = 0; in[i].opcode != NULL; i++)
		if (_strcmp(in[i].opcode, args[0]) == 0)
		{
			if ((q == 1) && (i == 0))
			{
				_rotr(head, line);
				in[i].f(head, line);
				_rotr(head, line);
			}
			else
				in[i].f(head, line);
			if (i == 14)
				free_args(args);
			return (0);
		}
	return (-1);
}

/**
 * check_int - checks if a string can be converted to int
 * @str: string
 * )
 * Return: 0 or -1
 */
int check_int(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (-1);
	}
	return (0);
}
