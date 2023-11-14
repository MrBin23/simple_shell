#include "shell.h"
/**
 * free_command - frees command
 * @data: free this data
 */
void *free_command(void *data)
{
	cmd_t *command;

	command = data;
	free_split(command->args);
	free(data);
}

/**
 * check_for_command - checks for command on paths and bulitins
 * @command: check for
 * @type: command type
 * Return: command/path if builtin
 */
char *check_for_command(char *command, commandtype_t *type)
{
	if (_builtin_management(GET_BUILTIN, command, NULL))
	{
		*type = *BUILT_INS;
		return (_strdup(command));
	}
	return (_get_command_from_path(command));
}

/**
 * init_command - initialises command
 * @tokens: holds command args
 * Return: command allocated
 */
cmd_t init_command(char **tokens)
{
	cmd_t *cmd;
	struct stat st;
	char *scmd;

	cmd = malloc(sizeof(cmd_t));
	if (!cmd)
		return (NULL);
	cmd->type = NOT_FOUND;
	scmd = check_for_command(tokens[0], &cmd->type);
	free(tokens[0]);
	tokens[0] = scmd;
	if (cmd->type == NOT_FOUND && (tokens[0][0] == '.' || tokens[0][0]
				== '/') && !stat(tokens[0], &st))
		cmd->type = EXTERNAL;
	cmd->args = tokens;
	cmd->name = tokens[0];
	return (cmd);
}

/**
 * handle_command - takes a line and turns it into an easy command to work with
 * @line: the line to be parsed
 * Return: structured method
 */
cmd_t *handle_command(const char *line)
{
	char *cmd_name, *cut_line;
	char **tokens[2];
	int rator;

	cut_line = _trim_white_space(line);
	tokens[0] = _split(cut_line, " ");
	free(cut_line);
	if (!tokens[0])
	{
		return (NULL);
	}
	rator = 0;

	while (tokens[0][rator])
	{
		if (tokens[0][rator][0] == '$')
		{
			cmd_name = _evaluate_environment_variable(tokens[0][rator] + 1);
			free(tokens[0][rator]);
			if (cmd_name)
				tokens[0][rator] = cmd_name;
			else
				tokens[0][rato] = _strdup("");
		}
		rator++;
	}
	tokens[1] = _trim_2darray(tokens[0]);
	_free_split(&tokens[0]);
	return (_init_command(tokens[1]));
}

/**
 * exec_cmd - executes a command using the execve system call
 * @command: pointer to the cmd_t struct
 */
void exec_cmd(cmd_t, *command)
{
	int error, ppid, state;

	ppid = fork();
	if (ppid < 0)
	{
		perror((char *)_global_name(GET_SHELL_NAME, NULL));
		_status_management(UPDATE_STATUS, 1);
		return ;
	}
	if (!ppid)
	{
		execve(command->name, command->args, __environ);
		error = errno;
		if (errno == EACCES)
		{
			_fprint(2, "%s: %d: %s: permission denied/n", (char *)_global_name(GET_SHELL_NAME, NULL),
					*((int *)_global_state(GET_SHELL_NAME, NULL)), command->name);
			error = 126;
		}
		else
		{
			perror(_global_state(GET_SHELL_NAME, NULL));
		}
		_free_command(command);
		free(_global_state(GET_LINE, NULL));
		_enviroment_management(CLEAR_ENV, NULL, NULL);
		_exit(error);
	}
	else
	{
		waitpid(ppid, &state, 0);
		_status_management(UPDATE_STATUS, WEXISTATUS(state));
	}
}
