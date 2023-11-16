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
	cmd_t *commd;
	int arg_len;

	iterator = colon_commd = _splits(lines, ";");
	if (!iterator)
	{
		return (1);
	}
	while (*iterator)
	{
		commd = handle_command(*iterator);
		if (commd->type == NOT_FOUND)
		{
			_fprint(2, "%s: %d: %s: not found\n",
				(char *)state_var_global(GET_SHELL_NAME, NULL),
				*((int *)state_var_global(GET_LINE_NUMBER, NULL)),
				commd->name);
			status_management(MY_STATUS_UPDATE, 127);
		}
		else if (commd->type == EXTERNAL)
			_handle_exec(commd);
		else
		{
			state_var_global(SET_2D, colon_commd);
			environ_access_management(MY_STATUS_UPDATE,
				built_in_management(
					GET_BUILTIN,
					commd->name, NULL)(commd));
		}
		arg_len = _string2dlenght(commd->args);
		environ_access_management(SET_ENTRY, "_", commd->args[arg_len - 1]);
		free_command(commd);
		iterator++;
	}
	free_split(&colon_commd);
	return (0);
}
/**
 * _handle_exec - function will give execution permission
 *
 *@commd: command that will be executed
 *Return: Nothing
 */
void _handle_exec(cmd_t *commd)
{
	if (access(commd->name, F_OK | X_OK) != -1)
		exec_cmd(commd);
	else
	{
	_fprint(2, "%s: %d: %s: permission denied\n",
		(char *)state_var_global(GET_SHELL_NAME, NULL),
		*((int *)state_var_global(GET_LINE_NUMBER, NULL)),
		commd->name);
	status_management(UPDATE_STATUS, 126);
	}
}
