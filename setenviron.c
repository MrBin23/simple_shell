#include "shell.h"
/**
 * setenviron - function will add new environ to entries
 *
 *@commd: struct stores new information about command
 *Return: Always success
 */
int setenviron(cmd_t *commd)
{
	int lenght;

	lenght = _string2dlenght(commd->args + 1);
	if (lenght != 2)
	{
		_fprint(2, "%s: invalid no of arguments\n",
			state_var_global(GET_SHELL_NAME, NULL));
		return (1);
	}
	environ_access_management(SET_ENTRY, commd->args[1],
		commd->args[2]);
	return (0);
}
