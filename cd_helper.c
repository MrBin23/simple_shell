#include "shell.h"
/**
 * cd_help_func - helper functions to change dir
 *
 *@keys: Environment variable
 *Return: Always sucess
 */
int cd_help_func(const char *keys)
{
	char *str;
	char buffer[200];

	getcwd(buffer, 200);
	str = environ_access_management(GET_VAL, keys, NULL);
	if (chdir(str) == -1)
	{
		free(str);
		return (errno);
	}
	environ_access_management(SET_ENTRY, "OLDPWD", buffer);
	free(str);
	return (0);
}
/**
 * cd_help_func2 - helper function 2
 *
 *@paths: helper functions for cd
 *Return: Always success
 */
int cd_help_func2(const char *paths)
{
	char buffer[300];

	getcwd(buffer, 300);
	if (chdir(paths) == -1)
	{
		perror(state_var_global(GET_SHELL_NAME, NULL));
		return (errno);
	}
	environ_access_management(SET_ENTRY, "OLDPWD", buffer);
	return (0);
}
/**
 * changedir - biut in function to change directory
 *
 *@commd: Buffer that stoes passed command
 *Return: Always success else 0
 */
int changedir(cmd_t *commd)
{
	int lenght;

	lenght = _string2dlenght(commd->args + 1);
	if (lenght >= 1)
	{
		if (_stringcompare("-", commd->args[1]))
			return (cd_help_func("OLDPWD"));
		else if (_stringcompare("~", commd->args[1]))
		return (cd_help_func2("HOME"));
		else
			return (cd_help_func2(commd->args[1]));
	}
	else if (!lenght)
		return (cd_help_func("HOME"));
	return (0);
}
