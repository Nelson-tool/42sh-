/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the left redirection '<' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "42sh.h"

bool exec_l_redir(shell_t *mysh, node_t *left, node_t *right)
{
	int save_stdin = dup(STDIN_FILENO);
	int in;

	if (right->expr != NULL)
		in = open(right->expr[0], O_RDONLY);
	else
		in = open(right->left->expr[0], O_RDONLY);
	if (in == -1) {
		ERROR_NO_FILE(right->expr[0]);
		return (false);
	}
	dup2(in, STDIN_FILENO);
	exec_tree(mysh, left);
	dup2(save_stdin, STDIN_FILENO);
	close(in);
	return (true);
}