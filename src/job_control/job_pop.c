/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Pops elements from the job linked list.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

pid_t job_pop_back(job_t **list)
{
	job_t *prev = NULL;
	job_t *cur = *list;
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
	job_free(cur);
	return (pid);
}

pid_t job_pop(job_t **list, int pos)
{
	job_t *prev = NULL;
	job_t *cur = *list;
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
	job_free(cur);
	return (pid);
}