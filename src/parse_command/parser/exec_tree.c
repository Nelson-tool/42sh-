/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Recursivily executes.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "42sh.h"

bool exec_tree(shell_t *mysh, node_t *tree)
{
	if (tree->op != EXPR) {
		if (!TOKENS_EXEC[tree->op](mysh, tree->left, tree->right))
			return (false);
	}
	else
		exec_command(mysh, tree->expr);
	return (true);
}