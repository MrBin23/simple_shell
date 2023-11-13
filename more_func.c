#include "shell.h"
/**
 * set_val - set a key-value pair ina  mapp by updating entry
 * @map: pointer to struct
 * @key: entry key
 * @val: entry value
 * Return: 0 or 1 on success
 */
int set_val(obj_t *map, const char *key, const char *val)
{
	int indx_backet;
	enter_t *enter;
	list_t *rator;

	indx_backet = gethash_code(key);
	rator = map->backets[indx_backet];
	while (rator)
	{
		enter = rator->data;
		if (_strcmp(enter->key, key))
		{
			free(enter->val);
			enter->val = _strdup(val);
			return (1);
		}

		rator = rator->next;
	}
	enter = malloc(sizeof(enter_t));
	if (!enter)
		return (0);
	enter->key = _strdup(key);
	enter->val = _strdup(val);
	add_to_list(&map->backets[indx_backet], enter);
	return (1);
}


