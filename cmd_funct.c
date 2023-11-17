#include "shell.h"
/**
 * free_command - frees command
 * @datas: free this data
 * Return: void
 */
void free_command(void *datas)
{
	cmd_t *command;

	command = datas;
	free_split(&command->args);
	free(datas);
}

/**
 * check_for_command - checks for command on paths and bulitins
 * @command: check for
 * @type: command type
 * Return: command/path if builtin
 */
char *check_for_command(char *command, commandtype_t *type)
{
	if (built_in_management(GET_BUILTIN, command, NULL))
	{
		*type = BUILTINS;
		return (_strdup(command));
	}
	return (get_cmd_path(command));
}

/**
 * init_command - initialises command
 * @tokens: holds command args
 * Return: command allocated
 */
cmd_t *init_command(char **tokens)
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

	cut_line = _rem_whitespace(line);
	tokens[0] = _splits(cut_line, " ");
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
			cmd_name = evaluate_env_var(tokens[0][rator] + 1);
			free(tokens[0][rator]);
			if (cmd_name)
				tokens[0][rator] = cmd_name;
			else
				tokens[0][rator] = _strdup("");
		}
		rator++;
	}
	tokens[1] = trim_array_2d(tokens[0]);
	free_split(&tokens[0]);
	return (init_command(tokens[1]));
}

/**
 * exec_cmd - executes a command using the execve system call
 * @command: pointer to the cmd_t struct
 */
void exec_cmd(cmd_t *command)
{
	int error, p_pid, state;

	p_pid = fork();
	if (p_pid < 0)
	{
		perror((char *)state_var_global(GET_SHELL_NAME, NULL));
		status_management(MY_STATUS_UPDATE, 1);
		return;
	}
	if (!p_pid)
	{
		execve(command->name, command->args, __environ);
		error = errno;
		if (errno == EACCES)
		{
			_fprint(2, "%s: %d: %s: permission denied\n",
					(char *)state_var_global(GET_SHELL_NAME, NULL),
					*((int *)state_var_global(GET_LINE_NUMBER, NULL)), command->name);
			error = 126;
		}
		else
		{
			perror(state_var_global(GET_SHELL_NAME, NULL));
		}
		free_command(command);
		free(state_var_global(GET_LINE, NULL));
		environ_access_management(CLEAR_ENVIRON, NULL, NULL);
		_exit(error);
	}
	else
	{
		waitpid(p_pid, &state, 0);
		status_management(MY_STATUS_UPDATE, WEXITSTATUS(state));
	}
}
