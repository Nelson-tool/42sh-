/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Displays the current jobs.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "shell.h"

void builtin_jobs(shell_t *mysh, UNUSED char **command)
{
	job_t *cur;
	int i = 0;

	job_cleanup(&mysh->jobs);
	cur = mysh->jobs;
	while (cur) {
		printf("[%d] %d %s\n", i + 1, cur->pid, cur->command);
		++i;
		cur = cur->next;
	}
	mysh->exit_status = 0;
}