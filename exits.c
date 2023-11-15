#include "shell.h"
/**
 * exits_func - function will exit commands
 *
 *@commd: command to exit from
 *Return: always success
 */
int exits_func(cmd_t *commd)
{
	char **iterates;
	int lenght;

	iterates = commd->args + 1;
	lenght = _string2dlenght(iterates);
	if (lenght > 0 && !isdigit(*iterates))
	{
		_fprint(2, "%s: %d: exit: Wrong number: %s\n",
			state_var_global(GET_SHELL_NAME, NULL),
			*((int *)state_var_global(GET_LINE_NUMBER, NULL)),
			commd->args[1]);
		return(2);
	}
	else
	{
		environ_access_variable(CLEAR_ENVIRON, NULL, NULL);
		free(state_var_global(GET_LINE, NULL));
		iterates = state_var_global(GET_2D, NULL);
		free_split(&iterates)
			if (!lenght)
			{
				free_command(commd);
				exits_func(environ_access_management(GET_STATUS, 0));
			}
		lenght = a_toi(commd->args[1];
			free_command(commd);
			exits_func(lenght);
	}
	return (0);
}
