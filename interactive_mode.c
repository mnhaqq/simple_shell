#include "main.h"

/**
 *interactive_mode - function for running shell in interactive mode
 *Return: 0
 */
int interactive_mode(void)
{
	int execute;
	size_t len = 0;
	ssize_t prompt;
	char *line = NULL;

	while (1)
	{
		_puts("$ ");
		prompt = getline(&line, &len, stdin);
		if (prompt == EOF)
		{
			_puts("\n");
			break;
		}
		if (line[prompt - 1] == '\n')
			line[prompt - 1] = '\0';
		if (_strncmp(line, "env", 3) == 0)
		{
			print_environment();
			free(line);
			break;
		}
		if (_strlen(line) == 0)
		{
			free(line);
			continue;
		}
		execute = execute_command(line);
		if (execute == -1)
			break;
	}
	free(line);
	return (0);
}

/**
 *execute_command - function to use fork system call to execute command
 *@line: command to be executed
 *Return: 0 or -1
 */
int execute_command(char *line)
{
	char **argv;
	pid_t pid;
	int status;

	argv = args_to_array(line);
	pid = fork();
	if (pid == -1)
	{
		perror("./hsh");
		free(argv);
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
			perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
	free_word_array(argv);
	return (0);
}
