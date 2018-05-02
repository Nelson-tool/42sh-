/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Executes a program from a path in the PATH.
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "my.h"
#include "42sh.h"

void print_error_signal(int exit_status)
{
	for (int i = 0 ; ERRORS_SIGNAL[i].signal ; ++i) {
		if (exit_status == ERRORS_SIGNAL[i].signal) {
			exit_status = ERRORS_SIGNAL[i].error_value;
			printf(ERRORS_SIGNAL[i].mssg);
			break;
		}
	}
}

void my_exec(shell_t *mysh, char *path, char **command)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1) {
		perror("fork");
		return;
	}
	if (child_pid == 0) {
		execve(path, command, mysh->env);
		perror("execve");
		exit(1);
	}
	waitpid(child_pid, &mysh->exit_status, 0);
	mysh->exit_status %= 128;
	print_error_signal(mysh->exit_status);
}