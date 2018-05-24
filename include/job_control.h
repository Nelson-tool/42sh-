/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** Headers for job control.
*/

#ifndef JOB_H
#define JOB_H

/* TYPEDEF */
typedef struct job {
	int pid;
	char *command;
	struct job *next;
} job_t;

/* FUNCTIONS */
//job_add.c
job_t *job_add(job_t **list, pid_t pid, node_t *tree);

//job_pop.c
pid_t job_pop_back(job_t **list);
pid_t job_pop(job_t **list, int pos);

//job_del.c
void job_free(job_t *proc);
void job_del_all(job_t *list);
void job_cleanup(job_t **job);

#endif