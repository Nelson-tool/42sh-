/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** Structures header file.
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct bg_process {
	int pid;
	char *command;
	struct bg_process *next;
} bg_process_t;

typedef struct shell {
	char **env;
	bg_process_t *bg_process;
	int tty;
	int exit_status;
	bool stop;
} shell_t;

#endif