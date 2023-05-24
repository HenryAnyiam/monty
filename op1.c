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

/**
 * _nop - do nothing
 * @head: pointer to top of stack
 * @line: line number
 */
void _nop(stack_t __attribute__ ((unused))  **head, unsigned int line)
{
	if (line)
		free_args(args);
}

/**
 * _sub - subtracts first and second element of stack
 * @head: pointer to top of stack
 * @line: line number
 */
void _sub(stack_t **head, unsigned int line)
{
	int temp;
	stack_t *current = *head;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		free_args(args);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	temp = (*head)->n - current->n;
	(*head)->n = temp;
	free(current);
	free_args(args);
}

/**
 * _div - divides first and second element of stack
 * @head: pointer to top of stack
 * @line: line number
 */
void _div(stack_t **head, unsigned int line)
{
	int temp;
	stack_t *current = *head;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		free_args(args);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free_args(args);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	temp = (*head)->n / current->n;
	(*head)->n = temp;
	free(current);
	free_args(args);
}

/**
 * _mul - multiplies first and second element of stack
 * @head: pointer to top of stack
 * @line: line number
 */
void _mul(stack_t **head, unsigned int line)
{
	int temp;
	stack_t *current = *head;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		free_args(args);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	temp = (*head)->n * current->n;
	(*head)->n = temp;
	free(current);
	free_args(args);
}
