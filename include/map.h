/*
** EPITECH PROJECT, 2018
** Dante
** File description:
** Generator header
*/

#ifndef MAP_H_
	#define MAP_H_

#include	"sokoban.h"

typedef	struct	s_cell		t_cell;

struct s_cell
{
	int value;
	int id;
};

enum		board {
	COLUMN = 0,
	LINE
};

enum		coor_cell {
	N = 0,
	S,
	E,
	W
};

enum		cell_pos {
	FI_NEIGHBOUR = 0,
	SE_NEIGHBOUR,
};

enum		neighbour_info_index {
	EX_X = 0,
	EX_Y = 1,
	NEW_X = 2,
	NEW_Y = 3,
	S_NEW_X = 4,
	S_NEW_Y
};

enum		cell_state {
	NONE = -1,
	FREE = 0,
	WALL = 1,
	BOX = 2,
	SLOT = 3,
	PLAYER = 4,
	PLAYER_ONSLOT = 5,
	BOX_ONSLOT = 6,
};
#endif
