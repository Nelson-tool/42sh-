/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the left double redirection '<<' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

bool exec_err(shell_t *mysh, node_t *left, int *data_channel, pid_t child_pid)
{
		close(data_channel[1]);
		if (dup2(data_channel[0], STDIN_FILENO) == -1) {
			perror("dup2");
			return (false);
		}
		if (waitpid(child_pid, &mysh->exit_status, 0) == -1) {
			perror("waitpid");
			return (false);
		}
		exec_tree(mysh, left);
		return (true);
}

bool exec_err_pf(int *data_channel, pid_t child_pid)
{	
	if (pipe(data_channel) == -1) {
		perror("pipe");
		return (false);
	}
	child_pid = fork();
	if (child_pid == -1) {
		perror("fork");
		return (false);
	}
	return (true);
}

static void get_input_to_redirect(const char *stop, int fd)
{
	char *line = NULL;

	do {
		if (line != NULL) {
			dprintf(fd, "%s\n", line);
			free(line);
		}
		my_putstr("? ");
		line = get_next_line(STDIN_FILENO);
	} while (line != NULL && strcmp(line, stop));
}

bool exec_l_dbl_redir(shell_t *mysh, node_t *left, node_t *right)
{
	int data_channel[2];
	int save_stdin = dup(STDIN_FILENO);
	pid_t child_pid = 0;

	if (exec_err_pf(data_channel, child_pid) == false)
		return (false);
	if (child_pid == 0) {
		close(data_channel[0]);
		get_input_to_redirect(right->expr[0], data_channel[1]);
		exit(mysh->exit_status);
	} else {
		if (!exec_err(mysh, left, data_channel, child_pid)) {
			if (dup2(save_stdin, STDIN_FILENO) == -1)
				perror("dup2");
			return (false);
		}
	}
	return (true);
}