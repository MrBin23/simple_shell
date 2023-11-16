#include "shell.h"
/**
 * status_management - manages status variable based on specified action
 * @cmd_action: action to perfrom on status variable
 * @new_status: updates status variable
 * Return: current value  of status variable
 */
int status_management(status_cmd_t cmd_action, int new_status)
{
	static int status;

	if (cmd_action == MY_STATUS_UPDATE)
	{
		status = new_status;
	}
	return (status);
}

/**
 * state_var_global - holds variables used in difreent places
 * @action: the action to perform on the global state
 * @str: pointer to a pointer ro a char, use dto pass or recieve data
 * Return: void
 */
void *state_var_global(global_cmd_t action, char **str)
{
	static char *my_line, *shell_name, **2darray;
	static int line_num;

	if (action == SET_LINE)
		my_line = *str;
	if (action == SET_SHELL_NAME)
		shell_name = *str;
	if (action == GET_LINE)
		return (my_line);
	if (action == GET_SHELL_NAME)
		return (shell_name);
	if (action == GET_LINE_NUMBER)
		return (&line_num);
	if (action == INCREMENT_LINE_NUMBER)
		line_num++;
	if (action == SET_2D)
		2darray = *str;
	if (action == GET_2D)
		return (2darray);
	return (NULL);
}

/**
 * environ_acces_var - allows global variable in programne
 * @action: applied to env
 * @key: used to add and recieve data
 * @val: value
 * Return: null
 */
void environ_access_management(environ_action_t action,
		const char *key, const char val)
{
	static obj_t *my_map;

	if (action == INIT_ENVIRON)
		my_map = init_mapt();
	else if (action == SET_ENTRY)
		set_val(my_map, key, val);
	else if (action == GET_VAL)
		return (_strdup(get_val(my_map, key)));
	else if (action == GET_KEYS)
		return (getkeys(my_map));
	else if (action == CONV_TO_2D)
		return (conv_env_to_2darray());
	else if (action == CLEAR_ENVIRON)
		clear_map(my_map);
	else if (action == DEL_ENTRY)
		del_entry(my_map, key);
	return (NULL);
}

/**
 * built_in_management - manages builtin in app
 * @action: action applied on builtin management
 * @name: builtin name
 * @function: executed function
 * Return: NULL
 */
builtin_t built_in_management(builtin_cmd_t action, char *name,
		int (*function)(cmd_t *cmd))
{
	static int obj_size;
	static builtin_t built[0];
	int rator;

	if (action == GET_BUILTIN)
	{
		rator = 0;
		while (rator < size)
		{
			if (_strcmp(built[rator].name, name))
				return (built[rator].functios);
			rator++;
		}
	}

	if (action == SET_BUILTIN)
	{
		_copy(built[obj_size].name, name, _strlen(name));
		built[obj_size].function = function;
		obj_size++;
	}
	return (NULL);
}
