#include "shell.h"
/**
 * setenviron - function will add new environ to entries
 *
 *@command: struct stores new information about command
 *Return: Always success
 */
int setenviron(cmd_t *command)
{
	int lenght;

	lenght = _string2dlenght(command->args + 1);
	if (lenght != 2)
	{
		_fprint(2, "%s: invalid no of arguments\n",
			state_var_global(GET_SHELL_NAME, NULL));
		return (1);
	}
	environ_access_management(SET_ENTRY, command->args[1],
		command->args[2]);
	return (0);
}
