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

static void redir_output(shell_t *mysh, node_t *left, int *pipefd)
{
	int save_stdout = dup(STDOUT_FILENO);
	int save_stderr = dup(STDERR_FILENO);

	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(pipefd[1], STDERR_FILENO);
	exec_tree(mysh, left);
	dup2(save_stdout, STDOUT_FILENO);
	dup2(save_stderr, STDERR_FILENO);
	exit(mysh->exit_status);
}

static void use_redirctd_input(shell_t *mysh, node_t *right, int *pipefd)
{
	int save_stdin = dup(STDIN_FILENO);

	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	exec_tree(mysh, right);
	dup2(save_stdin, STDIN_FILENO);
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
		redir_output(mysh, left, pipefd);
	else
		use_redirctd_input(mysh , right, pipefd);
	return (true);
}