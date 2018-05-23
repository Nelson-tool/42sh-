/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Displays the background processes.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "shell.h"

void builtin_jobs(shell_t *mysh, UNUSED char **command)
{
	bg_process_t *cur = mysh->bg_process;
	int i = 0;

	while (cur) {
		printf("[%d] %d\n", i + 1, cur->pid);
		++i;
		cur = cur->next;
	}
	mysh->exit_status = 0;
}