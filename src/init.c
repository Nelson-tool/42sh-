/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Initializes the program.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <wait.h>
#include "my.h"
#include "shell.h"

void sigint_hdl(UNUSED int signum)
{
	int status = 0;

	if (waitpid(-1, &status, WNOHANG) != -1) {
		putchar('\n');
		if (WIFSIGNALED(status))
			display_prompt();
	}
}

static void init_signal(void)
{
	struct sigaction sigint = {0};

	sigint.sa_handler = sigint_hdl;
	sigint.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sigint, NULL);
}

static node_t *get_config_command(shell_t *mysh, FILE *conf)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t byte_read = getline(&line, &n, conf);
	node_t *tree = NULL;

	if (byte_read == -1) {
		mysh->stop = true;
		free(line);
		return (NULL);
	}
	if (line[byte_read - 1] == '\n')
		line[byte_read - 1] = '\0';
	tree = parse_line(line, mysh);
	free(line);
	if (tree == NULL) {
		mysh->exit_status = 1;
		return (NULL);
	}
	return (tree);
}

static void exec_config_file(shell_t *shell)
{
	FILE *conf = fopen(CONF_FILE, "r");
	node_t *tree = NULL;

	if (conf == NULL)
		return;
	while (!shell->stop) {
		tree = get_config_command(shell, conf);
		if (tree != NULL) {
			exec_tree(shell, tree);
			del_tree(tree);
		}
	}
	shell->stop = false;
}

void init_shell(shell_t *shell, char **env)
{
	shell->env = env_dup(env);
	if (shell->env && get_pos_env(shell->env, "PATH") == -1)
		builtin_setenv(shell, DEFAULT_PATH);
	shell->tty = isatty(STDIN_FILENO);
	exec_config_file(shell);
	init_signal();
}