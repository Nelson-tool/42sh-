/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the right error double redirection '2>>' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

bool exec_r_err_dbl_redir(shell_t *mysh, node_t *left, node_t *right)
{
	int save_stderr = dup(STDERR_FILENO);
	int err;

	err = open(right->expr[0], O_WRONLY | O_CREAT | O_APPEND, REG_RIGHTS);
	if (err == -1) {
		perror("open");
		return (false);
	}
	dup2(err, STDERR_FILENO);
	exec_tree(mysh, left);
	dup2(save_stderr, STDERR_FILENO);
	close(err);
	return (true);
}