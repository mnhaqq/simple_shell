#include "main.h"

/**
 *print_environment - function to print env
 */
void print_environment(void)
{
	int i = 0;
	char *env_var = environ[i];

	while (env_var != NULL)
	{
		_puts(env_var);
		_puts("\n");
		i++;
		env_var = environ[i];
	}
}
