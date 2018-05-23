/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the bg_process linked list.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

bg_process_t *bg_process_add(bg_process_t **list, pid_t pid, char **command)
{
	bg_process_t *new_elem = malloc(sizeof(bg_process_t));
	bg_process_t *cur;

	if (new_elem == NULL) {
		perror("malloc");
		return (NULL);
	}
	new_elem->pid = pid;
	new_elem->command = my_str_join(command, " ");
	new_elem->next = NULL;
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

void bg_process_del_all(bg_process_t *list)
{
	bg_process_t *to_del;

	while (list) {
		to_del = list;
		list = list->next;
		free(to_del->command);
		free(to_del);
	}
}

pid_t bg_process_pop_back(bg_process_t **list)
{
	bg_process_t *prev = NULL;
	bg_process_t *cur = *list;
	pid_t pid;

	if (*list == NULL)
		return (0);
	while (cur->next) {
		prev = cur;
		cur = cur->next;
	}
	if (prev == NULL)
		*list = NULL;
	else
		prev->next = NULL;
	pid = cur->pid;
	free(cur->command);
	free(cur);
	return (pid);
}

pid_t bg_process_pop(bg_process_t **list, int pos)
{
	bg_process_t *prev = NULL;
	bg_process_t *cur = *list;
	pid_t pid;

	if (*list == NULL)
		return (0);
	for (int i = 0 ; i < pos ; ++i) {
		if (cur->next == NULL)
			return (0);
		prev = cur;
		cur = cur->next;
	}
	if (prev == NULL)
		*list = cur->next;
	else
		prev->next = cur->next;
	pid = cur->pid;
	free(cur->command);
	free(cur);
	return (pid);
}