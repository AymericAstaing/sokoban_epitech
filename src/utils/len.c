/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** PSU_minishell1_2018
*/

#include	"sokoban.h"
#include	"stdlib.h"

int	len(char const *str)
{
	int	i = 0;

	if (str == NULL)
		return (ERROR);
	while (str[i] != '\0') {
		i++;
	}
	return (i);
}
