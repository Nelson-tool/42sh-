/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Alias management.
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "shell.h"

char **parse_alias(char **str)
{
	char **alias = malloc(sizeof(char *) * 2);
	int i;
	int x;

	if (alias == NULL)
		return (NULL);
	for (; alias[1][x] != '='; ++x);
	alias[0] = malloc(sizeof(char) * x + 1);
	if (alias[0] == NULL)
		return (NULL);
	for (i = x; alias[1][x]; ++x);
	alias[1] = malloc(sizeof(char) * (x - i) + 1);
	if (alias[1] == NULL)
		return (NULL);
	for (x = 0; x <= i; ++x)
		alias[0][x] = str[1][x];
	for (++x; str[1][x]; ++x)
		alias[1][x] = str[1][x];
	return (alias);			
}

void add_alias(char **str, shell_t *mysh)
{
	char **alias = parse_alias(str);

	if (alias == NULL) {
		perror("malloc");
		return;
	}
	if (strcmp(alias[0], alias->alias) == 0)
		alias->cmd = strdup(alias[1]);			
	return;
}

void find_alias(char **left, char **right, shell_t *mysh)
{
	if (strcmp(left[0], "alias") == 0)
		add_alias(left, mysh);
	if (strcmp(right[0], "alias") == 0)
		add_alias(right, mysh);
	return;
}

void alias(node_t *node, shell_t *mysh)
{
	if (node->left != NULL)
		alias(node->left, mysh);
	if (node->right != NULL)
		alias(node->right, mysh);
	if (node->op == EXPR)
		find_alias(node->left->expr, node->right->expr, mysh);	
	//replace_alias()
}