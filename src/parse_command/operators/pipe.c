/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the pipe '|' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

bool exec_pipe(shell_t *mysh, node_t *left, node_t *right)
{
	int data_channel[2];
	int saves[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};
	pid_t child_process;

	pipe(data_channel);
	child_process = fork();
	if (child_process == 0) {
		close(data_channel[0]);
		dup2(data_channel[1], STDOUT_FILENO);
		exec_tree(mysh, left);
		dup2(saves[1], STDOUT_FILENO);
		exit(mysh->exit_status);
	} else {
		close(data_channel[1]);
		dup2(data_channel[0], STDIN_FILENO);
		exec_tree(mysh, right);
		dup2(saves[0], STDIN_FILENO);
	}
	return (true);
}