/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the and '&' operator.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "shell.h"

bool exec_job_and(shell_t *mysh, node_t *left, node_t *right)
{
	int child_pid = fork();

	if (child_pid == -1) {
		perror("fork");
		return (false);
	} else if (child_pid == 0) {
		setpgid(0, 0);
		exec_tree(mysh, left);
		if (tcgetpgrp(STDIN_FILENO) == getpgrp())
			tcsetpgrp(STDIN_FILENO, getppid());
		exit(mysh->exit_status);
	}
	bg_process_add(&mysh->bg_process, child_pid);
	exec_tree(mysh, right);
	return (true);
}