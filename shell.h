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

/**
 * struct cmd_s - holds information
 * @args: command argument
 * @name: command name
 * @type: command type
 */
typedef struct cmd_s
{
	char **args;
	char *name;
	commandtype_t type;
} cmd_t;


/**
 *
 */
typedef struct commandtype_s
{
	BUILT_INS, EXTERNAL, NOT_FOUND
} commandtype_t;

int a_toi(const char *str);
void clear_entry(void *data);

#endif
