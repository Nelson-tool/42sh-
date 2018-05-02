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

node_t *get_command(shell_t *mysh)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t byte_read = getline(&line, &n, stdin);
	node_t *tree = NULL;

	if (byte_read == -1) {
		mysh->stop = true;
		free(line);
		if (mysh->tty)
			puts("exit");
		return (NULL);
	}
	line[byte_read - 1] = '\0';
	tree = ll_lexer(line);
	free(line);
	if (tree == NULL) {
		mysh->exit_status = 1;
		return (NULL);
	}
	return (tree);
}