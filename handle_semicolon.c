#include "shell.h"
/**
 * handle_semicolon - function will split given line based on semi colon
 *
 *@lines: lines that will be parsed
 *Return: 0 on error and 1 on success
 */
int handle_semicolon(const char *lines)
{
	char **colon_commd;
	char **iterator;
	cmd_t *command;
	int arg_len;

	iterator = colon_commd = _splits(lines, ";");
	if (!iterator)
	{
		return (1);
	}
	while (*iterator)
	{
		command = handle_command(*iterator);
		if (command->type == NOT_FOUND)
		{
			_fprint(2, "%s: %d: %s: not found\n",
				(char *)state_var_global(GET_SHELL_NAME, NULL),
				*((int *)state_var_global(GET_LINE_NUMBER, NULL)),
				command->name);
			status_management(MY_STATUS_UPDATE, 127);
		}
		else if (command->type == EXTERNAL)
			_handle_exec(command);
		else
		{
			state_var_global(SET_2D, colon_commd);
			status_management(MY_STATUS_UPDATE,
				built_in_management(GET_BUILTIN,
					command->name, NULL)(command));
		}
		arg_len = _string2dlenght(command->args);
		environ_access_management(SET_ENTRY, "_", command->args[arg_len - 1]);
		free_command(command);
		iterator++;
	}
	free_split(&colon_commd);
	return (0);
}
/**
 * _handle_exec - function will give execution permission
 *
 *@command: command that will be executed
 *Return: Nothing
 */
void _handle_exec(cmd_t *command)
{
	if (access(command->name, F_OK | X_OK) != -1)
		exec_cmd(command);
	else
	{
	_fprint(2, "%s: %d: %s: permission denied\n",
		(char *)state_var_global(GET_SHELL_NAME, NULL),
		*((int *)state_var_global(GET_LINE_NUMBER, NULL)),
		command->name);
	status_management(MY_STATUS_UPDATE, 126);
	}
}
