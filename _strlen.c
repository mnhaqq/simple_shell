#include "main.h"

/**
 *_strlen - calculate length of string
 *@s: string
 *Return: length of string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 *_strcat - function to append one string to another
 *@dest: destination string
 *@src: source string
 *Return: pointer to resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++, i++)
		*(dest + i) = *(src + j);

	*(dest + i) = '\0';
	return (dest);
}

/**
 *_strcpy - function to copy string
 *@dest: destination string
 *@src: source string
 *Return: *dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		*(dest + i) = *(src + i);

	*(dest + i) = '\0';

	return (dest);
}

/**
 *_strncmp - function to compare 2 strings
 *@s1: string 1
 *@s2: string 2
 *@n: number of bytes
 *Return: 1, -1, 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*s1 - *s2);
}

/**
 *remove_extra_whitespace - fxt to remove whitespace from string
 *@str: string
 */
void remove_extra_whitespace(char *str)
{
	size_t dest_idx = 0;
	size_t src_idx = 0;
	bool prev_space = false;

	while (str[src_idx] != '\0')
	{
		if (str[src_idx] == ' ' || str[src_idx] == '\n')
		{
			if (!prev_space)
			{
				str[dest_idx++] = ' ';
				prev_space = true;
			}
		}
		else
		{
			str[dest_idx++] = str[src_idx];
			prev_space = false;
		}
		src_idx++;
	}
	str[dest_idx] = '\0';
}
