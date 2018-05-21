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

int main(UNUSED int ac, UNUSED char **av, char **envp)
{
	shell_t mysh = {0};

	init_shell(&mysh, envp);
	shell(&mysh);
	my_free_array((void **) mysh.env);
	return (mysh.exit_status);
}