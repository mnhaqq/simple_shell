#include "main.h"
/**
 *_puts - print string with newline at end
 *@str: string to be printed
 *Return: void
 */

void _puts(char *str)
{
	int i;
	char c;

	for (i = 0; str[i] != '\0'; i++)
	{
		c = str[i];
		_putchar(c);
	}
}

/**
 *_strchr - function that locates first occurence of a character in a string
 *@s: string
 *@c: character to be found
 *Return: pointer to first occurence of @c in @s or null if @c is not found
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	if (s[i] == c)
		return (s + i);

	return ('\0');
}

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * exit_builtin - Implementation of the exit shell builtin command
 * @args: Arguments passed to the exit command
 */
void exit_builtin(char **args)
{
	int exit_status = 0;

	if (args[1] != NULL)
		exit_status = atoi(args[1]);
	free(args);
	exit(exit_status);
}

/**
 *clear_whitespace - function to clear whitespace
 *@str: string
 */
void clear_whitespace(char *str)
{
	char *dest = str;
	char *src = str;

	while (*src != '\0')
	{
		if (!isspace((unsigned char)*src))
		{
			*dest = *src;
			dest++;
		}
		src++;
	}

	*dest = '\0';
}
