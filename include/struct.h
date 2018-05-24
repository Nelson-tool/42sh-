/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** Structures header file.
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct job job_t;
typedef struct alias alias_t;

typedef struct shell {
	char **env;
	job_t *jobs;
	alias_t *alias;
	int tty;
	int exit_status;
	bool stop;
} shell_t;

#endif