/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Recuperates the command from the users' input.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "42sh.h"

/*char **split_by_operators(char *line)
{
	char **command = NULL;

	for (int i = 0 ; )
}*/

node_t *get_command(shell_t *mysh)
{
	char *line = get_next_line(STDIN_FILENO);
	//char **array = NULL;
	node_t *tree = NULL;

	if (line == NULL) {
		mysh->stop = true;
		if (mysh->tty)
			my_putstr("exit\n");
		return (NULL);
	}
	//array = split_by_operators(line);
	tree = ll_lexer(line);
	free(line);
	if (tree == NULL) {
		mysh->exit_status = 1;
		return (NULL);
	}
	return (tree);
}