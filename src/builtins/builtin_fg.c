/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Takes a job and puts it in the foreground.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdbool.h>
#include "shell.h"

void builtin_fg(shell_t *mysh, UNUSED char **command)
{
	int bg_pid;

	job_cleanup(&mysh->jobs);
	if (mysh->jobs == NULL) {
		ERROR_FG_NO_JOBS;
		mysh->exit_status = 1;
		return;
	}
	bg_pid = job_pop_back(&mysh->jobs);
	tcsetpgrp(STDIN_FILENO, bg_pid);
	waitpid(bg_pid, &mysh->exit_status, 0);
}