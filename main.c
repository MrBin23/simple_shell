#include "shell.h"
/**
 * main - entry
 * @ac: passed args num
 * @av: arguments
 * Return: 0
 */
int main(int ac, char *av[])
{
	char *my_line;
	char *zero_line;

	(void)ac;
	signal(SIGINT, sigint_handler);
	environ_access_management(INIT_ENVIRON, NULL, NULL);
	feed_environ_var(__environ);
	built_in_management(SET_BUILTIN, "exit", _exitting);
	built_in_management(SET_BUILTIN, "env", _environmt);
	built_in_management(SET_BUILTIN, "setenv", setenviron);
	built_in_management(SET_BUILTIN, "unsetenv", _unsetenviron);
	built_in_management(SET_BUILTIN, "cd", changedir);
	state_var_global(SET_SHELL_NAME, &av[0]);

	while (1)
	{
		prompts();
		_getline(&my_line);
		if (!my_line)
		{
			free(my_line);
			break;
		}
		zero_line = _rem_whitespace(my_line);
		free(my_line);
		my_line = zero_line;
		state_var_global(SET_LINE, &my_line);
		state_var_global(INCREMENT_LINE_NUMBER, NULL);
		handle_semicolon(my_line);
		free(my_line);
	}
	environ_access_management(CLEAR_ENVIRON, NULL, NULL);
	return (status_management(GET_STATUS, 0));
}
