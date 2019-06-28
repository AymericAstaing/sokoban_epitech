/*
** EPITECH PROJECT, 2018
** my_exec.c
** File description:
** minishell1
*/

#include	<stdlib.h>
#include	"sokoban.h"
#include	"utils.h"

char	*my_strdup(char *str)
{
	char	*s = malloc(sizeof(char) * len(str) + 1);

	if (s == NULL)
		return (0);
	my_strcpy(s, str);
	return (s);
}