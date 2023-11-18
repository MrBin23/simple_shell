#include "shell.h"
/**
 * _unsetenviron - function unsets entry
 *
 *@command: Command contain info about entry
 *Return: Always success
 */
int _unsetenviron(cmd_t *command)
{
	int lenght;

	lenght = _string2dlenght(command->args);
	if (lenght != 2)
	{
		_fprint(2, "%s: invalid arguments\n",
			state_var_global(GET_SHELL_NAME, NULL));
		return (1);
	}
	environ_access_management(DEL_ENTRY, command->args[1], NULL);
	return (0);
}
