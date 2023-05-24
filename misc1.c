#include "monty.h"

/**
 * free_args - free args
 * @argt: args
 */
void free_args(char **argt)
{
	int i;

	if (argt != NULL)
		for (i = 0; argt[i] != NULL; i++)
			free(argt[i]);
	free(argt);
}

/**
  *_strdup - duplicates a string
  *@src: string to duplicate
  *)
  *Return: pointer to duplicate
  */
char *_strdup(const char *src)
{
	char *dup;
	size_t len, i = 0;

	if (src == NULL)
		return (NULL);
	len = strlen(src);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}

/**
 * _strcatint - concatenates a string and a char
 * @str: string
 * @c: char
 * )
 * Return: new string
 */
char *_strcatint(char *str, char c)
{
	int len, i;
	char *new;

	len = strlen(str);
	new = malloc(sizeof(char) * (len + 2));
	for (i = 0; str[i] != '\0'; i++)
		new[i] = str[i];
	new[i] = c;
	new[i + 1] = '\0';
	free(str);
	return (new);
}

/**
  *_strcmp - compares strings
  *@s1: string to compare
  *@s2: string to be compared with
  *)
  *Return: string difference
  */
int _strcmp(char *s1, char *s2)
{
	int i, j;

	i = 0;
	j = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			j = s1[i] - s2[i];
			break;
		}
		++i;
	}
	if ((j == 0) && (s1[i] != s2[i]))
		j = s1[i] - s2[i];
	return (j);
}

/**
*  _putchar - writes the character to c to stdout
* @c: The character to print
* Return: on sucess 1.
* on error, -1 is returned, and error is set appropriately
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

