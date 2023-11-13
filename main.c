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
	_environment_management(INIT_ENVIRON, NULL, NULL);
	_feed_environment_variable(__environ);
	_builtin_management(SET_BUILTIN, "exit", __exit);
	_builtin_management(SET_BUILTIN, "env", _env);
	_builtin_management(SET_BUILTIN, "setenv", _setenv);
	_builtin_management(SET_BUILTIN, "unsetenv", _unsetenv);
	_builtin_management(SET_BUILTIN, "cd", _cd);
	_global_states(SET_SHELL_NAME, &av[0]);

	while (1)
	{
		_prompt();
		_getline(&my_line);
		if (!my_line)
		{
			free(my_line);
			break;
		}
		zero_line = _trim_white_space(line);
		free(my_line);
		my_line = zero_line;
		_global_state(SET_LINE, &my_line);
		_global_state(INCREMENT_LINE_NUMBER, NULL);
		_semicolon_handler(my_line);
		free(my_line);
	}
	_environment_management(CLEAR_ENV, NULL, NULL);
	return (_status_management(GET_STATUS, 0));
}
