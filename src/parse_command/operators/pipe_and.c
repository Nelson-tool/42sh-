/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the pipe and '|&' operator.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

static bool setup_redir(int *pipefd, int *save_stdout, int *save_stderr)
{
	*save_stdout = dup(STDOUT_FILENO);
	if (*save_stdout == -1) {
		perror("dup");
		return (false);
	}
	*save_stderr = dup(STDERR_FILENO);
	if (*save_stderr == -1) {
		perror("dup");
		return (false);
	}
	if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
		perror("dup2");
		return (false);
	} else if (dup2(pipefd[1], STDERR_FILENO) == -1) {
		perror("dup2");
		dup2(*save_stdout, STDOUT_FILENO);
		return (false);
	}
	return (true);
}

static void redir_output_and_err(shell_t *mysh, node_t *left, int *pipefd)
{
	int save_stdout = dup(STDOUT_FILENO);
	int save_stderr = dup(STDERR_FILENO);

	if (close(pipefd[0]) == -1)
		perror("close");
	if (!setup_redir(pipefd, &save_stdout, &save_stderr))
		exit(1);
	exec_tree(mysh, left);
	if (dup2(save_stdout, STDOUT_FILENO) == -1)
		perror("dup2");
	if (dup2(save_stderr, STDERR_FILENO) == -1)
		perror("dup2");
	exit(mysh->exit_status);
}

bool exec_pipe_and(shell_t *mysh, node_t *left, node_t *right)
{
	int pipefd[2];
	pid_t child_process;

	if (pipe(pipefd) == -1) {
		perror("pipe");
		return (false);
	}
	child_process = fork();
	if (child_process == -1) {
		perror("fork");
		return (false);
	} else if (child_process == 0)
		redir_output_and_err(mysh, left, pipefd);
	else
		use_redirected_output(mysh , right, pipefd);
	return (true);
}