/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** Operators header.
*/

#ifndef OPERATORS_H
#define OPERATORS_H

/* INCLUDE */
#include <fcntl.h>


/* TYPEDEFS */
typedef enum {
	SEMICOLON,
	PIPE,
	R_DBL_REDIR,
	R_REDIR,
	L_DBL_REDIR,
	L_REDIR,
	EXPR
} token_t;

typedef struct node node_t;

/* FUNCTIONS */
//semicolon.c
bool no_error_operator(node_t *left, node_t *right);
bool exec_semicolon(shell_t *mysh, node_t *left, node_t *right);

//and.c
bool exec_and(shell_t *mysh, node_t *left, node_t *right);

//or.c
bool exec_or(shell_t *mysh, node_t *left, node_t *right);

//pipe.c
bool error_pipe(node_t *left, node_t *right);
bool exec_pipe(shell_t *mysh, node_t *left, node_t *right);

//right_dbl_redirection.c
bool exec_r_dbl_redir(shell_t *mysh, node_t *left, node_t *right);

//right_redirection.c
bool error_r_redir(node_t *left, node_t *right);
bool exec_r_redir(shell_t *mysh, node_t *left, node_t *right);

//left_dbl_redirection.c
bool exec_l_dbl_redir(shell_t *mysh, node_t *left, node_t *right);

//left_redirection.c
bool error_l_redir(node_t *left, node_t *right);
bool exec_l_redir(shell_t *mysh, node_t *left, node_t *right);


/* CONSTANTS */
static const char * const TK_SEMICOLON[] = {
	";",
	NULL
};

static const char * const TK_AND_OR[] = {
	"&&",
	"||",
	NULL
};

static const char * const TK_PIPE_RIGHT_REDIR[] = {
	"|",
	">>",
	">",
	NULL
};

static const char * const TK_LEFT_REDIR[] = {
	"<<",
	"<",
	NULL
};

static const char * const * const TOKENS_PRIOR[] = {
	TK_SEMICOLON,
	TK_AND_OR,
	TK_PIPE_RIGHT_REDIR,
	TK_LEFT_REDIR,
	NULL
};

static const char * const TOKENS[] = {
	";",
	"&&",
	"||",
	"|",
	">>",
	">",
	"<<",
	"<",
	NULL
};

static bool (*const ERROR_TOKEN[])
(node_t *left, node_t *right) = {
	no_error_operator,
	no_error_operator,
	no_error_operator,
	error_pipe,
	error_r_redir,
	error_r_redir,
	error_l_redir,
	error_l_redir
};

static const int REG_RIGHTS = S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR | S_IWOTH;

static bool (*const TOKENS_EXEC[])
(shell_t *mysh, node_t *left, node_t *right) = {
	exec_semicolon,
	exec_and,
	exec_or,
	exec_pipe,
	exec_r_dbl_redir,
	exec_r_redir,
	exec_l_dbl_redir,
	exec_l_redir
};


/* ERRORS */
#define ERROR_NULL_COMMAND		\
my_putstr("Invalid null command.\n")
#define ERROR_AMBIGUOUS_OUTPUT		\
my_putstr("Ambiguous output redirect.\n")
#define ERROR_AMBIGUOUS_INPUT		\
my_putstr("Ambiguous input redirect.\n")
#define ERROR_MISSING_NAME_REDIR		\
my_putstr("Missing name for redirect.\n")

#endif