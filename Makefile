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

SRC_COM		=	$(COM_DIR)/tree.c			\
			$(COM_DIR)/lexer/get_command.c		\
			$(COM_DIR)/lexer/ll_lexer.c		\
			$(COM_DIR)/lexer/split_node.c		\
			$(COM_DIR)/lexer/split_expressions.c	\
			$(COM_DIR)/lexer/check_syntax.c		\
			$(COM_DIR)/parser/exec_tree.c		\
			$(COM_DIR)/parser/exec_command.c	\
			$(COM_DIR)/parser/my_access.c		\
			$(COM_DIR)/parser/my_exec.c

SRC_OP		=	$(OP_DIR)/semicolon.c			\
			$(OP_DIR)/and.c				\
			$(OP_DIR)/or.c				\
			$(OP_DIR)/pipe.c			\
			$(OP_DIR)/right_dbl_redirection.c	\
			$(OP_DIR)/right_redirection.c		\
			$(OP_DIR)/left_dbl_redirection.c	\
			$(OP_DIR)/left_redirection.c		\

SRC_BUILT	=	$(BUILT_DIR)/builtin_exit.c		\
			$(BUILT_DIR)/builtin_env.c		\
			$(BUILT_DIR)/builtin_setenv.c		\
			$(BUILT_DIR)/builtin_unsetenv.c		\
			$(BUILT_DIR)/builtin_cd.c

SRC		=	src/main.c		\
			src/init.c		\
			src/env.c		\
			src/shell.c

OBJ		=	$(SRC:.c=.o)		\
			$(SRC_COM:.c=.o)	\
			$(SRC_OP:.c=.o)		\
			$(SRC_BUILT:.c=.o)

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
