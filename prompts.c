#include "shell.h"
/**
 * prompts - function will ask user to enter a prompt
 *
 * Return: Void i;e nothing
 */
void prompts(void)
{
	if (isatty(STDIN_FILENO))
	{
		_fprint(1, "%s> ", state_var_global(GET_SHELL_NAME, NULL));
	}
}
