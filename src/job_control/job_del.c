/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Deletes elements from the job linked list.
*/

#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

void job_free(job_t *proc)
{
	free(proc->command);
	free(proc);
}

void job_del_all(job_t *list)
{
	job_t *to_del;

	while (list) {
		printf("%d\n", list->pid);
		to_del = list;
		list = list->next;
		job_free(to_del);
	}
}

void job_cleanup(job_t **job)
{
	job_t *prev = NULL;
	job_t *cur = *job;

	while (cur) {
		if (waitpid(cur->pid, NULL, WNOHANG)) {
			if (prev == NULL) {
				*job = cur->next;
				job_free(cur);
				cur = *job;
			} else {
				prev->next = cur->next;
				job_free(cur);
				cur = prev->next;
			}
		} else {
			prev = cur;
			cur = cur->next;
		}
	}
}