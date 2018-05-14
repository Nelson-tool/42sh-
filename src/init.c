/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Initializes the program.
*/

#include <unistd.h>
#include <wait.h>
#include "my.h"
#include "42sh.h"

void sigint_hdl(UNUSED int signum)
{
	int status = 0;

	waitpid(-1, &status, 0);
	my_putchar('\n');
	if (!WIFSIGNALED(status))
		display_prompt();
}

/*__attribute__((constructor)) void init_signal(void)
{
	signal(SIGINT, &sigint_hdl);
}*/
