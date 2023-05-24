#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/*array of current arguments*/
extern char **args;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
int _putchar(char c);
ssize_t get_in(char **buf, int fd);
void free_stack(stack_t **head);
int set_args(char *buf);
int handle_op(stack_t **head, unsigned int line);
int check_int(char *str);
void free_args(char **argt);
void _push(stack_t **stack, unsigned int line);
void _pall(stack_t **stack, unsigned int line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(const char *src);
ssize_t _getline(char **buffer, size_t *size, int fd);
char *_strcatint(char *str, char c);
int _strcmp(char *s1, char *s2);
void _pint(stack_t **head, unsigned int line);
void _pop(stack_t **stack, unsigned int line);
void _swap(stack_t **stack, unsigned int line);
void _add(stack_t **stack, unsigned int line);
void _nop(stack_t **head, unsigned int line);
void _sub(stack_t **head, unsigned int line);
void _div(stack_t **head, unsigned int line);
void _mul(stack_t **head, unsigned int line);
void _mod(stack_t **head, unsigned int line);
void _pchar(stack_t **head, unsigned int line);
void _pstr(stack_t **head, unsigned int line);



#endif
