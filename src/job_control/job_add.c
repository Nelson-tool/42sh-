/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Adds a job.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

static void get_job_command(node_t *tree, char **command)
{
	char *join_expr;
	int len;

	if (tree->left != NULL)
		get_job_command(tree->left, command);
	if (tree->op == EXPR) {
		join_expr = my_str_join(tree->expr, " ");
		if (join_expr != NULL) {
			*command = my_append(*command, join_expr);
			free(join_expr);
		}
	} else {
		len = strlen(*command);
		*command = realloc(*command, len + 3 + strlen(TOKENS[tree->op]));
		if (*command != NULL)
			sprintf(*command + len, " %s ", TOKENS[tree->op]);
	}
	if (tree->right != NULL)
		get_job_command(tree->right, command);
}

static job_t *job_create(pid_t pid, node_t *tree)
{
	job_t *job = calloc(1, sizeof(job_t));

	if (job == NULL) {
		perror("malloc");
		return (NULL);
	}
	get_job_command(tree, &job->command);
	if (job->command == NULL) {
		perror("malloc");
		free(job);
		return (NULL);
	}
	job->pid = pid;
	return (job);
}

job_t *job_add(job_t **list, pid_t pid, node_t *tree)
{
	job_t *new_elem = job_create(pid, tree);
	job_t *cur;

	if (new_elem == NULL)
		return (NULL);
	if (*list == NULL)
		*list = new_elem;
	else {
		cur = *list;
		while (cur->next)
			cur = cur->next;
		cur->next = new_elem;
	}
	return (*list);
}