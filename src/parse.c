/*
** EPITECH PROJECT, 2018
** my_exec.c
** File description:
** minishell1
*/

#include	<ncurses.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"utils.h"
#include	"sokoban.h"
#include	"map.h"

int	get_value(char current)
{
	switch (current) {
		case 35:
			return (WALL);
		case 88:
			return (BOX);
		case 32:
			return (FREE);
		case 79:
			return (SLOT);
		case 80:
			return (PLAYER);
	}
	return (ERROR);
}

t_cell	get_none_cell(int pos)
{
	t_cell		cell;

	cell.value = NONE;
	cell.id = pos;
	return (cell);
}

t_cell	get_cell(char current, int pos)
{
	t_cell		cell;

	cell.value = get_value(current);
	cell.id = pos;
	return (cell);
}

int	parse_map(t_cell ***board, t_game_info **info, int max_x, int max_y)
{
	int	y = 0;
	char	c;
	int	total = 0;

	while (y < max_y) {
		(*board)[y] = (t_cell *)malloc(sizeof(t_cell) * (max_x));
		for (int x = 0; x < max_x; c = '\0', x++, total++) {
			if (x < len((*info)->first_board[y]))
				c = (*info)->first_board[y][x];
			if (c == PLAYER_SYMBOL)
				(*info)->player_pos = coor_to_pos(x, y, max_x);
			if (c == SLOT_SYMBOL)
				(*info)->slot_nbr++;
			if (IS_CORRECT_CELL(c) == SUCCESS)
				(*board)[y][x] = get_cell(c, total);
			else
				(*board)[y][x] = get_none_cell(total);
		}
		y++;
	}
	return (SUCCESS);
}
