#include "shell.h"
/**
 * evaluate_env_var - evaluates value of environ variable based of key
 * @environ_key: key to be evaluated
 * Return: value of environmet variable as a string
 */
char *evaluate_env_var(char *environ_key)
{
	int num;
	char *val;

	if (_strcmp(environ_key, "?"))
	{
		num = _status_management(GET_STATUS, 0);
		return (_itoa(num));
	}
	if (_strcmp(environ_key, "$"))
	{
		return(_itoa(getpid()));
	}
	val = _environment_management(GET_VALUE, environ_key, NULL);
	return (val);
}
