/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the semicolon ';' operator.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "42sh.h"

bool no_error_operator(UNUSED node_t *left, UNUSED node_t *right)
{
	return (false);
}

bool exec_semicolon(shell_t *mysh, node_t *left, node_t *right)
{
	exec_tree(mysh, left);
	exec_tree(mysh, right);
	return (true);
}