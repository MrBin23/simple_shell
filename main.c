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

	void(ac);
	signal(SIGINT, _handle_sigint);
	environ_access_management(INIT_ENVIRON, NULL, NULL);
	feed_environ_var(__environ);
	built_in_management(SET_BUILTIN, "exit", __exit);
	built_in_management(SET_BUILTIN, "env", _env);
	built_in_management(SET_BUILTIN, "setenv", _setenv);
	built_in_management(SET_BUILTIN, "unsetenv", _unsetenv);
	built_in_management(SET_BUILTIN, "cd", _cd);
	state_var_global(SET_SHELL_NAME, &av[0]);

	while (1)
	{
		_prompt();
		_getline(&my_line);
		if (!my_line)
		{
			free(my_line);
			break;
		}
		zero_line = _rem_whitespace(line);
		free(my_line);
		my_line = zero_line;
		state_var_global(SET_LINE, &my_line);
		state_var_global(INCREMENT_LINE_NUMBER, NULL);
		handle_semicolon(my_line);
		free(my_line);
	}
	enviiron_access_management(CLEAR_ENVIRON, NULL, NULL);
	return (status_management(GET_STATUS, 0));
}
