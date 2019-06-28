/*
** EPITECH PROJECT, 2018
** my_exec.c
** File description:
** minishell1
*/

#include	<ncurses.h>
#include	<stdlib.h>
#include	"sokoban.h"

int	*arrows_pressed(int key, int pos, int x_map)
{
	int	*concerned_cells = malloc(sizeof(int) * 2);

	switch (key) {
		case KEY_UP:
			concerned_cells[FI_NEIGHBOUR] = pos - (x_map);
			concerned_cells[SE_NEIGHBOUR] = pos - (2 * x_map);
			break;
		case KEY_DOWN:
			concerned_cells[FI_NEIGHBOUR] = pos + x_map;
			concerned_cells[SE_NEIGHBOUR] = pos + (2 * x_map);
			break;
		case KEY_LEFT:
			concerned_cells[FI_NEIGHBOUR] = pos - 1;
			concerned_cells[SE_NEIGHBOUR] = pos - 2;
			break;
		case KEY_RIGHT:
			concerned_cells[FI_NEIGHBOUR] = pos + 1;
			concerned_cells[SE_NEIGHBOUR] = pos + 2;
			break;
	}
	return (concerned_cells);
}
