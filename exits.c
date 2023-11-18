#include "shell.h"
/**
 * exits_func - function will exit commands
 *
 *@command: command to exit from, the main command
 *Return: always success
 */
int exits_func(cmd_t *command)
{
	char **iterates;
	int lenght;

	iterates = command->args + 1;
	lenght = _string2dlenght(iterates);
	if (lenght > 0 && !_isdigit(*iterates))
	{
		_fprint(2, "%s: %d: exit: Wrong number: %s\n",
			state_var_global(GET_SHELL_NAME, NULL),
			*((int *)state_var_global(GET_LINE_NUMBER, NULL)),
			command->args[1]);
		return (2);
	}
	else
	{
		environ_access_management(CLEAR_ENVIRON, NULL, NULL);
		free(state_var_global(GET_LINE, NULL));
		iterates = state_var_global(GET_2D, NULL);
		free_split(&iterates);
			if (!lenght)
			{
				free_command(command);
				_exit(status_management(GET_STATUS, 0));
			}
		lenght = a_toi(command->args[1]);
			free_command(command);
			_exit(lenght);
	}
	return (0);
}
