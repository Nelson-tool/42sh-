/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Takes a bacground process and puts it in the fore ground.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdbool.h>
#include "shell.h"

void bg_process_cleanup(bg_process_t **bg_process)
{
	bg_process_t *prev = NULL;
	bg_process_t *cur = *bg_process;

	while (cur) {
		if (waitpid(cur->pid, NULL, WNOHANG)) {
			if (prev == NULL) {
				*bg_process = cur->next;
				free(cur);
				cur = *bg_process;
			} else {
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		} else {
			prev = cur;
			cur = cur->next;
		}
	}
}

void builtin_fg(shell_t *mysh, UNUSED char **command)
{
	int bg_pid;

	bg_process_cleanup(&mysh->bg_process);
	if (mysh->bg_process == NULL) {
		ERROR_FG_NO_JOBS;
		mysh->exit_status = 1;
		return;
	}
	bg_pid = bg_process_pop_back(&mysh->bg_process);
	tcsetpgrp(STDIN_FILENO, bg_pid);
	waitpid(bg_pid, &mysh->exit_status, 0);
}