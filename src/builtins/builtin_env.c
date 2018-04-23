/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Displays the env.
*/

#include "my.h"
#include "42sh.h"

void builtin_env(shell_t *mysh, UNUSED char **command)
{
	for (int i = 0 ; mysh->env[i] ; ++i)
		my_printf("%s\n", mysh->env[i]);
	mysh->exit_status = 0;
}