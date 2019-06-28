/*
** EPITECH PROJECT, 2018
** my_exec.c
** File description:
** minishell1
*/

#include	<unistd.h>
#include	<ncurses.h>
#include	"sokoban.h"
#include	"utils.h"
#include	"map.h"

int	free_moove(t_cell *new_cell, t_cell *ex_cell)
{
	if (new_cell->value == SLOT)
		new_cell->value = PLAYER_ONSLOT;
	else
		new_cell->value = PLAYER;
	if (ex_cell->value == PLAYER_ONSLOT)
		ex_cell->value = SLOT;
	else
		ex_cell->value = FREE;
	return (SUCCESS);
}

int	moove_box(t_cell *player, t_cell *current_box, t_cell *new_cell, t_game_info **info)
{
	int	next_next_cell = new_cell->value;

	if (next_next_cell != FREE && next_next_cell != SLOT)
		return (ERROR);
	if (current_box->value == BOX_ONSLOT) {
		(*info)->slot_ok--;
		current_box->value = PLAYER_ONSLOT;
	} else {
		current_box->value = PLAYER;
	}
	if (new_cell->value == SLOT) {
		(*info)->slot_ok++;
		new_cell->value = BOX_ONSLOT;
	} else {
		new_cell->value = BOX;
	}
	if (player->value == PLAYER_ONSLOT)
		player->value = SLOT;
	else
		player->value = FREE;
	return (SUCCESS);
}
