#ifndef SHELL_H
#define SHELL_H

#define BUFF_SIZE 1024
#define BACKET_SIZE 64
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

typedef enum environ_action_s
{
	GET_VAL, GET_KEYS, INIT_ENVIRON,
	SET_ENTRY, DEL_ENTRY, CLEAR_ENVIRON,
	CONV_TO_2D
} environ_action_t;

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
 */
typedef enum builtin_cmd_s
{
	GET_BUILTIN,
	SET_BUILTIN
} builtin_cmd_t;

/**
 *
 */
typedef struct commandtype_s
{
	BUILT_INS, EXTERNAL, NOT_FOUND
} commandtype_t;

/**
 */
typedef struct obj_s
{
	list_t *backets[BACKET_SIZE];
} obj_t;

/**
 */
typedef enum status_cmd_s
{
	MY_STATUS_UPDATE, GET_STATUS
} status_cmd_t;

/**
 */
typedef enum global_cmd_s
{
	GET_LINE, GET_LINE_NUMBER, GET_SHELL_NAME, SET_LINE,
	SET_SHELL_NAME, INCREMENT_LINE_NUMBER, SET_2D, GET_2D
} global_cmd_t;

int a_toi(const char *str);
void clear_entry(void *data);

#endif
