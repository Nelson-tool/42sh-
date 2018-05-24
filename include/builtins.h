/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Header file for builtins.
*/

#ifndef BUILTINS_H
#define BUILTINS_H

/* TYPEDEF */
typedef struct builtin {
	const char *name;
	void (*ptr)(shell_t *mysh, char **command);
} builtin_t;


/* FUNCTIONS */
//builtin_exit.c
void builtin_exit(shell_t *mysh, char **command);

//builtin_env.c
void builtin_env(shell_t *mysh, char **command);

//builtin_setenv.c
void builtin_setenv(shell_t *mysh, char **command);

//builtin_unsetenv.c
void builtin_unsetenv(shell_t *mysh, char **command);

//builtin_cd.c
void builtin_cd(shell_t *mysh, char **command);

//builtin_pwd.c
void builtin_pwd(shell_t *mysh, char **command);

//builtin_echo.c
void builtin_echo(shell_t *mysh, char **command);

//builtin_jobs.c
void builtin_jobs(shell_t *mysh, char **command);

//builtin_fg.c
void builtin_fg(shell_t *mysh, char **command);

//builtin_alias.c
void set_alias(shell_t *mysh, const char *name, const char *value);
void builtin_alias(shell_t *mysh, char **command);

//builtin_unalias.c
void builtin_unalias(shell_t *mysh, char **command);

//builtin_true.c
void builtin_true(shell_t *mysh, char **command);

//builtin_false.c
void builtin_false(shell_t *mysh, char **command);

/* CONSTANTS */
static const builtin_t BUILTINS[] = {
	{"exit", builtin_exit},
	{"env", builtin_env},
	{"setenv", builtin_setenv},
	{"unsetenv", builtin_unsetenv},
	{"cd", builtin_cd},
	{"pwd", builtin_pwd},
	{"echo", builtin_echo},
	{"jobs", builtin_jobs},
	{"fg", builtin_fg},
	{"alias", builtin_alias},
	{"unalias", builtin_unalias},
	{"true", builtin_true},
	{"false", builtin_false}
};

static const int NB_BUILTINS = 13;

static const char ECHO_SEQS[] = "abcefnrtv";
static const int NB_ECHO_SEQS = 8;


/* ERRORS */
//exit
#define ERROR_EXIT_EXPRESSION		\
puts("exit: Expression Syntax.")

//setenv
#define ERROR_SETENV_TOO_MANY_ARG		\
puts("setenv: Too many arguments.")
#define ERROR_SETENV_FIRST_CHAR		\
puts("setenv: Variable name must begin with a letter.")
#define ERROR_SETENV_ALPHA_NUM		\
puts("setenv: Variable name must contain alphanumeric characters.")

//unsetenv
#define ERROR_UNSETENV_TOO_FEW_ARG		\
puts("unsetenv: Too few arguments.")

//cd
#define ERROR_CD_HOME		\
puts("cd: Can't change to home directory.")
#define ERROR_CD_TOO_MUCH_ARG		\
puts("cd: Too many arguments.")
#define ERROR_CD_NOT_DIR(name)		\
printf("%s: Not a directory.\n", name)

//pwd
#define ERROR_PWD_TOO_MANY_ARG		\
puts("pwd: too many arguments")
#define ERROR_PWD_BAD_OPTION(opt)		\
printf("pwd: bad option: %s\n", opt)

//fg
#define ERROR_FG_NO_JOBS		\
puts("fg: no current job")

//unalias
#define ERROR_UNALIAS_TOO_FEW_ARG		\
puts("unalias: Too few arguments")

#endif
