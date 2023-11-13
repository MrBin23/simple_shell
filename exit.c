#include "shell.h"
/**
 * _exitting - function which exit from the program
 *
 *@commd: Structure holding data bout command
 *Return: 0 success else error
 */
int _exitting(command_t *commd)
{
	char **iterates;
	int lenght;

	iterates = commd->arguments + 1;
	lenght = _str2dlen(iterates);
	if (lenght > 0 && !_isdigit(*iterates))
	{
		_fprint(2, "%: %d: exit: illegal number: %s\n",
			_global_states(GET_SHELL_NAME, NULL),
			*((int *)_global_states(GET_LINE_NUMBER, NULL)),
			commd->arguments[1]);
		return (2);
	}
	else
	{
		_enviroment_management(CLEAR_ENV, NULL, NULL);
		free(_global_states(GET_LINE, NULL));
		iterates = _global_states(GET_2D, NULL);
		_free_split(&iterates);
		if (!lenght)
		{
			_free_command(commd);
			_exit(_status_management(GET_STATUS, 0));
		}
		lenght = _atoi(commd->arguments[1]);
		_free_command(commd);
		_exit(lenght);
	}
		return (0);
}
