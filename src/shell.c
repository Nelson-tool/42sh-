/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Heart of the project.
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <linux/limits.h>
#include "my.h"
#include "42sh.h"

void display_prompt(void)
{
	char path[PATH_MAX + 1] = "";
	char *dir;

	getcwd(path, PATH_MAX);
	dir = rindex(path, '/');
	dprintf(STDOUT_FILENO, "(42sh %s)$ ", (dir == path) ? dir : dir + 1);
}

void shell(shell_t *mysh)
{
	node_t *tree = NULL;

	while (!mysh->stop) {
		if (mysh->tty)
			display_prompt();
		tree = get_command(mysh);
		if (tree != NULL) {
			exec_tree(mysh, tree);
			del_tree(tree);
		}
	}
}