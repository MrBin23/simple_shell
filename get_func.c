#include "shell.h"
/**
 * get_cmd_path - gets command and return its path
 * @command: looks for its path
 * Return: located path command
 */
char *get_cmd_path(char *command)
{
	char *my_cmd, *my_path, **_dpath, **rator;

	struct stat st;

	if ((command[0] == '.' || command[0] == '/') && !stat(command, &st))
	{
		return (_strdup(command));
	}
	my_path = environ_access_management(GET_VAL, "PATH", NULL);
	if (!my_path)
		return (_strdup(command));
	rator = _dpath = _splits(my_path, ":");
	free(my_path);

	while (*rator)
	{
		my_path = _strcat(*rator, "/");
		my_cmd = _strcat(my_path, command);
		free(my_path);
		if (!stat(my_cmd, &st))
		{
			free_split(&_dpath);
			return (my_cmd);
		}
		free(my_cmd);
		rator++;
	}
	free_split(&_dpath);
	return (_strdup(command));
}

/**
 * gethash_code - calcautes hash code for a key
 * @key: hashed key
 * Return: hash code of key
 */
int gethash_code(const char *key)
{
	int my_hash, j;

	my_hash = 0;
	for (j = 0; key[j] != '\0'; j++)
	{
		my_hash = my_hash + key[j];
	}
	return (my_hash % BACKET_SIZE);
}

/**
 * get_val - retrieves the associated value with a given key
 * @mapp: object containing key value pair
 * @key: to search for value
 * Return: value associated with key if not found
 */
char *get_val(obj_t *mapp, const char *key)
{
	int indx_backt;
	list_t *backt;
	enter_t *enter;

	indx_backt = gethash_code(key);
	backt = mapp->backets[indx_backt];
	while (backt)
	{
		enter = backt->datas;
		if (_stringcompare(enter->key, key))
			return (enter->value);
		backt = backt->next;
	}
	return (NULL);
}

/**
 * init_mapt - initialises a new hash table
 * Return: pointer to map inintialised
 */
obj_t *init_mapt(void)
{
	obj_t *my_map;
	int rator;

	my_map = (obj_t *)malloc(sizeof(obj_t));
	rator = 0;

	while (rator <  BACKET_SIZE)
	{
		my_map->backets[rator] = NULL;
		rator++;
	}
	return (my_map);
}
