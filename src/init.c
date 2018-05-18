/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Initializes the program.
*/

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

__attribute__((constructor)) void init_signal(void)
{
	struct sigaction sigint = {0};

	sigint.sa_handler = sigint_hdl;
	sigint.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sigint, NULL);
}
