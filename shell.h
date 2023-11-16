#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <sys/stat.h>

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

/**
 * enum environ_action_s - action on environment global
 * @GET_VAL: gets value from environment
 * @GET_KEYS: gets keys saved in enviroment var
 * @INIT_ENVIRON: initialises environ variable
 * @SET_ENTRY: add entry to environ variable
 * @DEL_ENTRY: deletes entry from environ variable
 * @CLEAR_ENVIRON: frees environ
 * @CONV_TO_2D: returns 2d arrays
 */
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
 * enum builtin_cmd_s - buitin commands and actions
 * @GET_BUILTIN: get builtin commands
 * @SET_BUILTIN: set builtin commands
 */
typedef enum builtin_cmd_s
{
	GET_BUILTIN,
	SET_BUILTIN
} builtin_cmd_t;

/**
 * struct commandtype_s - type of a command
 * @BUILT_INS: means command is built in
 * @EXTERNAL: an external command
 * @NOT_FOUND: command not found
 */
typedef struct commandtype_s
{
	BUILT_INS, EXTERNAL, NOT_FOUND
} commandtype_t;

/**
 * struct obj_s - defines struct for has table
 * @backets: array of linked list
 */
typedef struct obj_s
{
	list_t *backets[BACKET_SIZE];
} obj_t;

/**
 * struct builtin_e - contains number of functions to be
 * executed and builtins
 * @name: buitin name
 * @function: buitin function
 */
typedef struct builtin_e
{
	char name[30];
	int (*function)(cmd_t *command);
} builtin_t;

/**
 * enum status_cmd_s - action on status state management
 * @GET_STATUS: retrieves status code
 * @MY_STATUS_UPDATE: update status code
 */
typedef enum status_cmd_s
{
	MY_STATUS_UPDATE, GET_STATUS
} status_cmd_t;

/**
 * enum global_cmd_s - action on global state var
 * @GET_LINE: gets a line
 * @GET_LINE_NUMBER: gets current line number
 * @GET_SHELL_NAME: gets shell name
 * @SET_LINE: allow to set line
 * @SET_SHELL_NAME: allows to set shell name
 * @INCREMENT_LINE_NUMBER: increment number by one
 * @SET_2D: sets 2d array
 * @GET_2D: gets 2d array
 */
typedef enum global_cmd_s
{
	GET_LINE, GET_LINE_NUMBER, GET_SHELL_NAME, SET_LINE,
	SET_SHELL_NAME, INCREMENT_LINE_NUMBER, SET_2D, GET_2D
} global_cmd_t;

typedef int (*builtins_t)(cmd_t *);


/**Betvic prototype**/
int a_toi(const char *str);
void clear_entry(void *datas);
int del_entry(map_t *map, const char *key);
void *free_command(void *datas);
char *_itoa(int num);
int count_num_len(int num);
int *move_from_list(list_t **my_list);
char *_strcat(const char *str1, const char *str2);
char *_strdup(const char *str);
char *str_slice(const char *my_line, int start, int end);
char *evaluate_env_var(char *environ_key);
int set_val(obj_t *map, const char *key, const char *val);
void sigint_handler(int sign);
int count_string(char **str);
char **trim_array_2d(char **str);
char *get_cmd_path(char *cmd);
int gethash_code(const char *key);
char *get_val(obj_t *obj, const char *key);
obj_t *init_mapt(void);
int _fputs(int fd, const char *str);
int fputs_num(int fd, int num);
int _fprint(int fd, const char *format, ...);
int fputs_num_help(int fd, int num);
char *check_for_command(char *command, commandtype_t *type);
cmd_t init_command(char **tokens);
cmd_t *handle_command(const char *line);
void exec_cmd(cmd_t *command);
int main(int ac, char *av[]);
void *feed_environ_var(**env);
char **conv_env_to_2darray(void);
void *state_var_global(global_cmd_t action, char **str);
void environ_access_management(environ_action_t action,
		const char *key, const char val);
builtin_t built_in_management(builtin_cmd_t action, char *name,
		int (*function)(cmd_t *cmd));
void *_realloc(void *prev_buff, size_t prev_size, size_t new_size);


/**Ay structs**/
/**
 * struct list_s - nodes of a linked list
 * @datas: content of  a linked list
 * @next: the next node
 */
typedef struct list_s
{
	void *datas;
	struct list_s *next
} list_t;

/** Add_new_node.c file AY**/
list_t *add_new_node(list_t **lists, void *datas);
void map_clear(obj_t *mapp);
void _freelist(list_t *lists, void (*free_cont)(void *datas);
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
int exits_func(cmd_t *commd);
int cd_help_func(const char *keys);
int cd_help_func2(const char *paths);
int changedir(cmd_t *commd);

#endif
