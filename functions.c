#include "shell.h"
/**
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
