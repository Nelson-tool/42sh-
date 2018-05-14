/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Recuperates the command from the users' input.
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "42sh.h"

static void cut_comment(char *str)
{
	char *com = index(str, '#');

	if (com != NULL)
		*com = '\0';
}

static node_t *parse_line(char *line)
{
	node_t *tree = NULL;

	cut_comment(line);
	if (!check_quotes(line))
		return (NULL);
	tree = ll_lexer(line);
	return (tree);
}

node_t *get_command(shell_t *mysh)
{
	char *line = get_next_line(STDIN_FILENO);
	node_t *tree = NULL;

	if (line == NULL) {
		mysh->stop = true;
		if (mysh->tty)
			my_putstr("exit\n");
		return (NULL);
	}
	tree = parse_line(line);
	free(line);
	if (tree == NULL) {
		mysh->exit_status = 1;
		return (NULL);
	}
	return (tree);
}
