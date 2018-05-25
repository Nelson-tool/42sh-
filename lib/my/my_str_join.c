/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Joins a string array into a single string.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my.h"

static int get_arr_tot_size(char **arr)
{
	int tot = 0;

	for (int i = 0 ; arr[i] ; ++i)
		tot += strlen(arr[i]);
	return (tot);
}

char *my_str_join(char **arr, const char *joint)
{
	int nb_elem = my_strlen_tab((void *) arr);
	int joint_len = strlen(joint);
	int tot_size = get_arr_tot_size(arr) + joint_len + 1;
	char *str = malloc(sizeof(char) * (tot_size));
	char *tmp = str;

	if (str == NULL) {
		perror("malloc");
		return (NULL);
	}
	for (int i = 0 ; i < nb_elem + nb_elem - 1 ; ++i) {
		if (!(i & 1)) {
			strcpy(tmp, arr[i / 2]);
			tmp += strlen(arr[i / 2]);
		} else {
			strcpy(tmp, joint);
			tmp += joint_len;
		}
	}
	return (str);
}