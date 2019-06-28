/*
** EPITECH PROJECT, 2018
** my_exec.c
** File description:
** minishell1
*/

#include	<stdlib.h>
#include	"sokoban.h"
#include	"utils.h"

char	*my_strcpy(char *dest, char const *src)
{
	int	a = 0;

	while (src[a]) {
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
