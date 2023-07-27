#include "main.h"

/**
 *read_textfile - function to read a text file and tokenize it into array
 *@filename: pointer to name of file
 *@letters: number of characters to be read
 *Return: number of letters or 0
 */
char **read_textfile(const char *filename, size_t letters)
{
	int fo, fr;
	char *buffer;
	char **arr;

	if (filename == NULL)
		return (NULL);

	buffer = malloc(sizeof(char) * (1 + letters));
	if (buffer == NULL)
		return (NULL);

	fo = open(filename, O_RDONLY);
	if (fo == -1)
	{
		free(buffer);
		return (NULL);
	}
	fr = read(fo, buffer, letters);
	if (fr == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[fr] = '\0';
	arr = args_to_array(buffer);
	free(buffer);
	close(fo);
	return (arr);
}
