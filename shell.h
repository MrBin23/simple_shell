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

**Ay structs**
/**
 *
 */
typedef struct list_s
{
	void *datas;
	struct list_s *next
} list_t;

** Add_new_node.c file AY**
list_t *add_new_node(list_t **lists, void *datas);
void map_clear(obj_t *mapp);
void _freelist(list_t *lists, void (*free_cont)(void *data);
char *_copies(char *dest, const char *source, size_t size);
int _environmt(command_t *commd);
char *remove_comment(const char *lines);
int _exitting(cmd_t *commd);
int isdigit(const char *str);
size_t listlenght(const list *lists);
int _string2dlenght(char **array2d);
void free_split(char ***backs);
int get_comment_pos(const char *lines);
size_t search_nextnewline(char *buff, size_t lenght);
size_t _getline(char **lines);
void *_realloc(void *prev_buff, size_t prev_size, size_t new_size);
size_t _stringlenght(const char *string);
int handle_error_parsing(char *lines);
int check_invalid_char_occur(char *lines);
int handle_semicolon(const char *lines);
int check_diam(const char *string, const char *diam);
void free_backs(char **backs, size_t curr_pos);
size_t backs_counter(const char *lines, const char *diam);
size_t find_next_diam(const char *lines, const char *diam);
char **_splits(const char *lines, const char *diam);
char *_rem_whitespace(const char *lines);
size_t _get_lenght_withnospace(const char *lines, size_t ends);
size_t *_get_newline_withnospace(const char *lines, size_t ends);

#endif
