#include "monty.h"

/**
 * _mod - divides first and second element of stack
 * @head: pointer to top of stack
 * @line: line number
 */
void _mod(stack_t **head, unsigned int line)
{
	int temp;
	stack_t *current = *head;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
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
	temp = (*head)->n % current->n;
	(*head)->n = temp;
	free(current);
	free_args(args);
}


/**
 * _pchar - To print the char at the top of the stack
 * @head: pointer to the head of the stack
 * @line: line number
 * Return:void
 */

void _pchar(stack_t **head, unsigned int line)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		free_args(args);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*head)->n < 0 || (*head)->n > 255)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
			free_args(args);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
		else

		{
			_putchar((*head)->n);
			_putchar(10);
		}
	}
	free_args(args);
}

/**
 * _pstr - to print string starting from top stack
 * @head: pointer to the top of the stack
 * @line: line
 * Return: null
 */
void _pstr(stack_t **head, unsigned int line)
{
	stack_t *temp = *head;

	(void)line;

	if (*head == NULL)
		_putchar(10);
	while (temp != NULL && temp->n != 0 && (temp->n >= 0 || temp->n <= 127))
	{
		_putchar(temp->n);
		temp = temp->next;
	}
	_putchar(10);
	free_args(args);

}





























