#include "shell.h"
/**
 * del_entry - delete entry from map based on given key
 * @map: map from which to delete entry
 * @key: key of entry to be deleted
 * Return: 0 if entry was deleted
 */
int del_entry(map_t *map, const char *key)
{
	list_t *my_list, *temp;
	int ret_ind;
	enter_t *my_entry;

	ret_ind = _get_hash_code(key);
	my_list = map->backets[ret_ind];
	if (!list)
		return (0);
	my_entry = list->data;
	if (_strcmp(my_entry->key, key))
	{
		map->backets[ret_ind] = list->next;
		_clear_entry(list->data);
		free(list);
		return (0);
	}
	while (list->next)
	{
		my_entry = list->next->data;
		if (_strcmp(my_entry->key, key))
		{
			temp = list->next;
			list->next = list->next->next;
			_clear_entry(temp->data);
			free(temp);
			break;
		}
		list = list->next;
	}
	return (0);
}
