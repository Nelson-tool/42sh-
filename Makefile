##
## EPITECH PROJECT, 2017
## 42sh
## File description:
## Makefile for 42sh
##

CC		=	gcc

RM		=	rm

COM_DIR		=	src/parse_command

OP_DIR		=	src/parse_command/operators

BUILT_DIR	=	src/builtins

ALIAS_DIR	=	src/alias

JOB_DIR		=	src/job_control

SRC_COM		=	$(COM_DIR)/tree.c			\
			$(COM_DIR)/lexer/get_command.c		\
			$(COM_DIR)/lexer/check_quotes.c		\
			$(COM_DIR)/lexer/ll_lexer.c		\
			$(COM_DIR)/lexer/split_node.c		\
			$(COM_DIR)/lexer/check_syntax.c		\
			$(COM_DIR)/lexer/split_expressions.c	\
			$(COM_DIR)/lexer/split_argv.c		\
			$(COM_DIR)/lexer/apply_alias.c		\
			$(COM_DIR)/parser/exec_tree.c		\
			$(COM_DIR)/parser/exec_command.c	\
			$(COM_DIR)/parser/my_access.c		\
			$(COM_DIR)/parser/my_exec.c

SRC_OP		=	$(OP_DIR)/semicolon.c			\
			$(OP_DIR)/and.c				\
			$(OP_DIR)/or.c				\
			$(OP_DIR)/pipe_and.c			\
			$(OP_DIR)/pipe.c			\
			$(OP_DIR)/right_dbl_redirection.c	\
			$(OP_DIR)/right_err_dbl_redirection.c	\
			$(OP_DIR)/right_and_dbl_redirection.c	\
			$(OP_DIR)/right_redirection.c		\
			$(OP_DIR)/right_err_redirection.c	\
			$(OP_DIR)/right_and_redirection.c	\
			$(OP_DIR)/left_dbl_redirection.c	\
			$(OP_DIR)/left_redirection.c		\
			$(OP_DIR)/job_and.c			\
			$(OP_DIR)/error_patterns.c

SRC_BUILT	=	$(BUILT_DIR)/builtin_exit.c		\
			$(BUILT_DIR)/builtin_env.c		\
			$(BUILT_DIR)/builtin_setenv.c		\
			$(BUILT_DIR)/builtin_unsetenv.c		\
			$(BUILT_DIR)/builtin_cd.c		\
			$(BUILT_DIR)/builtin_pwd.c              \
			$(BUILT_DIR)/builtin_echo.c             \
			$(BUILT_DIR)/builtin_echo_opts.c        \
			$(BUILT_DIR)/builtin_help.c		\
			$(BUILT_DIR)/builtin_jobs.c		\
			$(BUILT_DIR)/builtin_fg.c		\
			$(BUILT_DIR)/builtin_alias.c		\
			$(BUILT_DIR)/builtin_unalias.c		\
			$(BUILT_DIR)/builtin_true.c		\
			$(BUILT_DIR)/builtin_false.c		\
			$(BUILT_DIR)/builtin_repeat.c

SRC_ALIAS	=	$(ALIAS_DIR)/set_alias.c	\
			$(ALIAS_DIR)/find_alias.c	\
			$(ALIAS_DIR)/show_alias.c	\
			$(ALIAS_DIR)/del_alias.c

SRC_JOB		=	$(JOB_DIR)/job_add.c	\
			$(JOB_DIR)/job_pop.c	\
			$(JOB_DIR)/job_del.c	\
			$(JOB_DIR)/job_list.c

SRC		=	src/main.c		\
			src/init.c		\
			src/env.c		\
			src/shell.c

OBJ		=	$(SRC:.c=.o)		\
			$(SRC_COM:.c=.o)	\
			$(SRC_OP:.c=.o)		\
			$(SRC_BUILT:.c=.o)	\
			$(SRC_ALIAS:.c=.o)	\
			$(SRC_JOB:.c=.o)

CPPFLAGS	+=	-I include

CFLAGS		+=	-Wall -Wextra

LDFLAGS		+=	-Llib/ -lmy

NAME		=	42sh

all	:	$(NAME)

$(NAME)	:	lib	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

lib	:	lib/my/Makefile
		make -C lib/my

tests_run:	lib
		make -C tests/
		./tests/units

clean	:
		$(RM) -f $(OBJ)
		make clean -C lib/my
		make clean -C tests

fclean	:	clean
		$(RM) -f $(NAME)
		make fclean -C lib/my
		make fclean -C tests

re	:	fclean	all

.PHONY	:	all lib tests_run clean fclean re
