#include "monty.h"

/**
 * _add - adds first and second element of stack
 * @head: pointer to top of stack
 * @line: line number
 */
void _add(stack_t **head, unsigned int line)
{
	int temp;
	stack_t *current = *head;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_args(args);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	temp = current->n + (*head)->n;
	(*head)->n = temp;
	free(current);
	free_args(args);
}
