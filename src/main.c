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

int main(int ac, char **av, char **envp)
{
	shell_t mysh = {0};

	init_shell(&mysh, ac, av, envp);
	shell(&mysh);
	my_free_array((void **) mysh.env);
	return (mysh.exit_status);
}