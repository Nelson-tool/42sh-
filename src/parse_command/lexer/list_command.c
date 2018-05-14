/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Transforms the command into a double linked list.
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "42sh.h"

/*static int find_token(const char *line, int *token)
{
        int i;

        *token = -1;
        for (i = 0 ; *token == -1 && line[i] ; ++i) {
                for (int j = 0 ; TOKENS[j] ; ++j) {
                        if (!strncmp(line + i, TOKENS[j], strlen(TOKENS[j]))) {
                                *token = j;
                                --i;
                                break;
                        }
                }
        }
        return (i);
}

static bool add_last_expr(node_t *list)
{
        if (list == NULL)
                return (true);
        while (list->right)
                list = list->right;
        if (list->op != EXPR)
                return (add_expr_list(&list, "", 0));
        return (true);
}

node_t *list_command(char *line)
{
	node_t *first = NULL;
	int token;
	int pos;

	while (line[0]) {
                pos = find_token(line, &token);
		if (!add_expr_list(&first, line, pos) ||
			(token != -1 && !add_token_list(&first, token))) {
			cleanup_list(first);
			return (NULL);
		}
		line += pos + ((token != -1) ? strlen(TOKENS[token]) : 0);
	}
        if (!add_last_expr(first)) {
                cleanup_list(first);
                return (NULL);
        }
	return (first);
}*/
