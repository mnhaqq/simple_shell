#include "main.h"

/**
 *args_to_array - function to parse input into an array
 *@args: input
 *Return: array containing parsed input
 */
char **args_to_array(char *args)
{
	int word_count = 1, i;
	char **word_array;
	char *current_word;

	/*word count */
	for (i = 0; args[i]; i++)
	{
		if (args[i] == ' ')
			word_count++;
	}

	word_array = malloc(sizeof(char *) * (1 + word_count));
	if (word_array == NULL)
		return (NULL);
	current_word = strtok(args, " ");
	for (i = 0; current_word != NULL; i++)
	{
		word_array[i] = current_word;
		current_word = strtok(NULL, " ");
	}
	word_array[i] = NULL;
	return (word_array);
}

/**
 *free_word_array - function to free dynamically allocated memory
 *@word_array: array to be freed
 */
void free_word_array(char **word_array)
{
	int i;

	if (word_array == NULL)
		return;

	for (i = 0; word_array[i] != NULL; i++)
		free(word_array[i]);
	free(word_array);
}
