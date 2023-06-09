#include "monty.h"

/**
 * _push - add to a stack
 * @head: pointer to stack
 * @line: line
 */
void _push(stack_t **head, unsigned int line)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(head);
		free_args(args);
		exit(EXIT_FAILURE);
	}
	if ((args[1] == NULL) || (check_int(args[1]) == -1))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		free(new);
		free_stack(head);
		free_args(args);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(args[1]);
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	free_args(args);
}

/**
 * _pall - prints all in a stack
 * @head: pointer to stack
 * @line: line
 */
void _pall(stack_t **head, unsigned int __attribute__ ((unused)) line)
{
	stack_t *current = *head;

	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	free_args(args);
}

/**
 * _pint - To print the top of the stack
 * @head: pointer to the head of the stack
 * @line: line number
 * Return:void
 */

void _pint(stack_t **head, unsigned int line)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		free_args(args);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stdout, "%d\n", (*head)->n);
	free_args(args);
}

/**
 * _pop - remove top on the stack
 * @head: pointer to top of stack
 * @line: line number
 */
void _pop(stack_t **head, unsigned int line)
{
	stack_t *current = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free_args(args);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	free(current);
	free_args(args);
}

/**
 * _swap - swaps first and second element of stack
 * @head: pointer to top of stack
 * @line: line number
 */
void _swap(stack_t **head, unsigned int line)
{
	int temp;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_args(args);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	temp = ((*head)->next)->n;
	((*head)->next)->n = (*head)->n;
	(*head)->n = temp;
	free_args(args);
}
