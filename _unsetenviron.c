#include "shell.h"
/**
 * _unsetenviron - function unsets entry
 *
 *@commd: Command contain info about entry
 *Return: Always success
 */
int _unsetenviron(command_t *commd)
{
	int lenght;

	lenght = _string2dlenght(command->args);
	if (lenght != 2)
	{
		_fprint(2, "%s: invalid arguments\n", _global_states(GET_SHELL_NAME, NULL));
		return (1);
	}
	_enviroment_management(DELETE_ENTRY, commd->args[1], NULL);
	return (0);
}
