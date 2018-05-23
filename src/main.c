/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** Main file.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "shell.h"

static void cleanup_shell(shell_t *mysh)
{
	if (mysh->env != NULL)
		my_free_array((void **) mysh->env);
	if (mysh->bg_process != NULL)
		free(mysh->bg_process);
	if (mysh->alias != NULL)
		del_alias(mysh->alias);
}

int main(int ac, char **av, char **envp)
{
	shell_t mysh = {0};

	init_shell(&mysh, ac, av, envp);
	shell(&mysh);
	cleanup_shell(&mysh);
	return (mysh.exit_status);
}