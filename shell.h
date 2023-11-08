#ifndef SHELL_H
#define SHELL_H

/**
 * struct enter_s - holds value and key of hash table
 * @value: key data
 * @key: retrieves value
 */
typedef struct enter_s
{
	char *value;
	char *key;
} enter_t;

int a_toi(const char *str);

#endif
