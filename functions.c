#include "shell.h"
/**
 * _itoa - converts num to string
 * @num: number to be converted
 * Return: string converted
 */
char *_itoa(int num)
{
	char *num_str;
	int length;

	length = count_num_len(num);
	num_str = malloc(sizeof(char) * (length + 1));
	if (!num_str)
		return (NULL);
	num_str[length] = 0;
	if (!num)
	{
		num_str[0] = '0';
		return (num_str);
	}
	if (num < 0)
	{
		num_str[0] = '-';
		num *= -1;
	}
	while (num)
	{
		num_str[--length] = num % 10 + 48;
		num /= 10;
	}
	return (num_str);
}

/**
 * count_num_len - calculates lenth of number
 * @num: number to calculate length
 * Return: length
 */
int count_num_len(int num)
{
	int length;

	length = 0;
	if (num == 0)
	{
		return (1);
	}
	if (num <  0)
	{
		length++;
		num *= -1;
	}
	while (num)
	{
		length++;
		num /= 10;
	}
	return (length);
}

/**
 * move_from_list - removes first first node from linked_list
 * @my_list: pointer to pointer that head linked list
 * Return: data contained in first node
 */
int *move_from_list(list_t **my_list)
{
	list_t *node_moved = *my_list;
	void *removed_data = removed_data->datas;

	if (!my_list && *my_list == NULL)
		return (NULL);
	*my_list = node_moved->next;
	free(node_moved);

	return (removed_data);
}
