#include "main.h"

/**
 *sep_commands - fxn to separate cmmands with semi colon
 *@args: argumentnts
 *Return: array of commands
 */
char **sep_commands(char *args)
{
	int word_count = 1, i;
	char **word_array;
	char *current_word;

	for (i = 0; args[i]; i++)
	{
		if (args[i] == ';')
			word_count++;
	}

	word_array = malloc(sizeof(char *) * (1 + word_count));
	if (word_array == NULL)
		return (NULL);
	current_word = strtok(args, ";");
	for (i = 0; current_word != NULL; i++)
	{
		word_array[i] = current_word;
		current_word = strtok(NULL, ";");
	}
	word_array[i] = NULL;
	return (word_array);
}

