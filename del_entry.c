#include "shell.h"
/**
 * del_entry - delete entry from map based on given key
 * @map: map from which to delete entry
 * @key: key of entry to be deleted
 * Return: 0 if entry was deleted
 */
int del_entry(obj_t *map, const char *key)
{
	list_t *my_list, *temp;
	int ret_ind;
	enter_t *my_entry;

	ret_ind = gethash_code(key);
	my_list = map->backets[ret_ind];
	if (!my_list)
		return (0);
	my_entry = my_list->datas;
	if (_strcmp(my_entry->key, key))
	{
		map->backets[ret_ind] = my_list->next;
		clear_entry(my_list->datas);
		free(my_list);
		return (0);
	}
	while (my_list->next)
	{
		my_entry = my_list->next->datas;
		if (_strcmp(my_entry->key, key))
		{
			temp = my_list->next;
			my_list->next = my_list->next->next;
			clear_entry(temp->datas);
			free(temp);
			break;
		}
		my_list = my_list->next;
	}
	return (0);
}
