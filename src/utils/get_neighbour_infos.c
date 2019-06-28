/*
** EPITECH PROJECT, 2018
** my_exec.c
** File description:
** minishell1
*/

#include	<ncurses.h>
#include	<stdlib.h>
#include	"sokoban.h"
#include	"utils.h"
#include	"map.h"

int	*get_neighbour_infos(int *new_cells, int ex_cell, int x_map)
{
	int	*neighbour_infos = malloc(sizeof(int) * 6);

	neighbour_infos[EX_X] = pos_to_coor(ex_cell, x_map)[X];
	neighbour_infos[EX_Y] = pos_to_coor(ex_cell, x_map)[Y];
	neighbour_infos[NEW_X] = pos_to_coor(new_cells[FI_NEIGHBOUR],
	x_map)[X];
	neighbour_infos[NEW_Y] = pos_to_coor(new_cells[FI_NEIGHBOUR],
	x_map)[Y];
	neighbour_infos[S_NEW_X] = pos_to_coor(new_cells[SE_NEIGHBOUR],
	x_map)[X];
	neighbour_infos[S_NEW_Y] = pos_to_coor(new_cells[SE_NEIGHBOUR],
	 x_map)[Y];
	return (neighbour_infos);
}
