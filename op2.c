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
