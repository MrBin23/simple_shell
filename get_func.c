#include "shell.h"
/**
 * get_cmd_path - gets command and return its path
 * @cmd: looks for its path
 * Return: located path command
 */
char *get_cmd_path(char *cmd)
{
	char *my_cmd, *my_path, **2dpath, **rator;

	struct stat st;

	if ((cmd[0] == '.' || cmd[0] == '/') && !stat(cmd, &st))
	{
		return (_strdup(cmd));
	}
	my_path = environ_access_management(GET_VAL, "PATH", NULL);
	if (!my_path)
		return (_strdup(cmd));
	rator = 2dpath = _split(path, ":");
	free(my_path);

	while (*rator)
	{
		my_path = _strcat(*rator, "/");
		my_cmd = _strcat(path, cmd);
		free(my_path);
		if (!stat(my_cmd, &st))
		{
			free_split(&2dpath);
			return (my_cmd);
		}
		free_split(&2dpath);
		return (_strdup(cmd));
	}
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
	for (i = 0; key[j]; != '\0'; j++)
	{
		my_hash = my_hash + key[j];
	}
	return (hash % BACKET_SIZE);
}

/**
 * get_val - retrieves the associated value with a given key
 * @obj: object containing key value pair
 * @key: to search for value
 * Return: value associated with key if not found
 */
char *get_val(obj_t *obj, const char *key)
{
	int indx_backt;
	list_t *backt;
	enter_t *enter;

	indx_backt = gethash_code(key);
	backt = obj->backets[indx_backt];
	while (backt)
	{
		enter = backt->datas;
		if (_strcmp(enter->key, key))
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

	my_map = malloc(sizeof(obj_t));
	rator = 0;

	while (rator <  BACKET_SIZE)
	{
		my_map->backets[rator] = NULL;
		rator++;
	}
	return (my_map);
}
