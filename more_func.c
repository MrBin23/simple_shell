#include "shell.h"
/**
 * set_val - set a key-value pair ina  mapp by updating entry
 * @map: pointer to struct
 * @key: entry key
 * @val: entry value
 * Return: 0 or 1 on success
 */
int set_val(obj_t *map, const char *key, const char *value)
{
	int indx_backet;
	enter_t *enter;
	list_t *rator;

	indx_backet = gethash_code(key);
	rator = map->backets[indx_backet];
	while (rator)
	{
		enter = rator->datas;
		if (_stringcompare(enter->key, key))
		{
			free(enter->value);
			enter->value = _strdup(value);
			return (1);
		}

		rator = rator->next;
	}
	enter = malloc(sizeof(enter_t));
	if (!enter)
		return (0);
	enter->key = _strdup(key);
	enter->value = _strdup(value);
	add_new_node(&map->backets[indx_backet], enter);
	return (1);
}

/**
 * sigint_handler - signal handler function for SIGINT signal(ctrl + c)
 * @sign: signal number
 */
void sigint_handler(int sign)
{
	(void)sign;
	fflush(stdin);
	if (isatty(STDIN_FILENO))
	{
		_fprint(1, "\n%s> ", state_var_global(GET_SHELL_NAME, NULL));
	}
}
