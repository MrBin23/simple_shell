#include "shell.h"
/**
 * feed_environ_var - feeds environ varible into a  system
 * environment function
 * @env: pointer to array of environ variable
 * Return: void
 */
void feed_environ_var(char **env)
{
	char **new_entry;

	while (*env)
	{
		new_entry = _splits(*env, "=");
		environ_access_management(SET_ENTRY, new_entry[0], new_entry[1]);
		free_split(&new_entry);
		env++;
	}
}

/**
 * conv_env_to_2darray - turns environment int 2d array
 * Return: NULL or arry
 */
char **conv_env_to_2darray(void)
{
	list_t *my_key, *rator;
	char **arry;
	char *temp[2];
	size_t len;

	rator = my_key = environ_access_management(GET_KEYS, NULL, NULL);
	len = listlenght(my_key);
	arry = malloc(sizeof(char *) * (len + 1));
	if (!arry)
	{
		_freelist(my_key, free);
		return (NULL);
	}
	arry[len] = NULL;
	len = 0;
	while (rator)
	{
		temp[0] = _strcat(rator->datas, "=");
		temp[1] = environ_access_management(GET_VAL, rator->datas, NULL);
		arry[len] = _strcat(temp[0], temp[1]);
		free(temp[0]);
		free(temp[1]);
		rator = rator->next;
		len++;
	}
	_freelist(my_key, free);
	return (arry);
}
