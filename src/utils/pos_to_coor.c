/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** PSU_minishell1_2018
*/

#include	<stdlib.h>
#include	"sokoban.h"

int	*pos_to_coor(int pos, int x_map)
{
	int	*coor = malloc(sizeof(int) * 2);
	coor[X] = pos / x_map;
	coor[Y] = pos % x_map;
	return (coor);
}
