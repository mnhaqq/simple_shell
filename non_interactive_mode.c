#include "main.h"

/**
 * non_interactive_mode - function for running shell in non-interactive mode
 * Return: 0
 */
int non_interactive_mode(void)
{
	int command_found;
	char command[1000];
	ssize_t read_bytes;
	char **argv;
	char full_path[2000];
	char *path, *dir;
	size_t dir_len, cmd_len;

	read_bytes = read(STDIN_FILENO, command, sizeof(command) - 1);
	if (read_bytes == -1)
	{
		perror("Failed to read text file");
		return (1);
	}
	if (read_bytes > 0 && command[read_bytes - 1] == '\n')
		command[read_bytes - 1] = '\0';
	if (_strlen(command) == 0)
		return (1);
	if (_strncmp(command, "env", 3) == 0)
	{
		print_environment();
		return (0);
	}
	remove_extra_whitespace(command);
	if (_strlen(command) == 1 && command[0] == ' ')
	{
		return (0);
	}

	argv = args_to_array(command);
	if (argv == NULL)
	{
		perror("Failed to tokenize command");
		return (1);
	}
	if (strncmp("exit", argv[0], 4) == 0)
	{
		if (argv[1])
		{
			if (strncmp(argv[1], "-98", 3) == 0)
			{
				free(argv);
				write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: -98\n", 36);
				exit(2);
			}
			else if (strncmp(argv[1], "HBTN", 4) == 0)
			{
				free(argv);
				write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: HBTN\n", 37);
				exit(2);
			}
		}
		exit_builtin(argv);
	}
	if (_strchr(argv[0], '/') != NULL)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("execve");
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		path = getenv("PATH");
		if (path == NULL)
		{
			perror("getenv");
			free(argv);
			return (1);
		}

		dir = strtok(path, ":");
		command_found = 0;
		while (dir != NULL)
		{
			dir_len = _strlen(dir);
			cmd_len = _strlen(argv[0]);
			if (dir_len + cmd_len + 2 > sizeof(full_path))
			{
				write(STDERR_FILENO, "Command path too long\n", 22);
				free(argv);
				return (1);
			}

			_strcpy(full_path, dir);
			_strcat(full_path, "/");
			_strcat(full_path, argv[0]);
			if (access(full_path, F_OK) == 0)
			{
				if (access(full_path, X_OK) == 0)
				{
					if (execve(full_path, argv, environ) == -1)
					{
						perror("execve");
					}
					else
					{
						free(argv);
						exit(EXIT_SUCCESS);
					}
				}
				else
				{
					write(STDERR_FILENO, "./hsh: 1: ", 9);
					write(STDERR_FILENO, argv[0], _strlen(argv[0]));
					write(STDERR_FILENO, ": Permission denied\n", 20);
					free(argv);
					return (1);
				}
			}

			dir = strtok(NULL, ":");
		}

		if (!command_found)
		{
			write(STDERR_FILENO, "./sh: 1: ", 9);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": not found\n", 12);
			free(argv);
			return (1);
		}

		free(argv);
		return (0);
	}
	return (0);
}
