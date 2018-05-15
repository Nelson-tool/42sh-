/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the right double redirection '>>' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

bool exec_r_dbl_redir(shell_t *mysh, node_t *left, node_t *right)
{
	int save_stdout = dup(STDOUT_FILENO);
	int out;

	out = open(right->expr[0], O_WRONLY | O_CREAT | O_APPEND, REG_RIGHTS);
	if (out == -1) {
		perror("open");
		return (false);
	}
	dup2(out, STDOUT_FILENO);
	exec_tree(mysh, left);
	dup2(save_stdout, STDOUT_FILENO);
	close(out);
	return (true);
}