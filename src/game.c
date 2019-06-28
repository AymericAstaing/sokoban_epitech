/*
** EPITECH PROJECT, 2018
** my_exec.c
** File description:
** minishell1
*/

#include	<ncurses.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"sokoban.h"
#include	"utils.h"
#include	"map.h"

int	action(int *new_cells, int ex, t_cell **board, t_game_info **g_i)
{
	int	*i = get_neighbour_infos(new_cells, ex, (*g_i)->x_map);
	int	next_case = board[i[NEW_X]][i[NEW_Y]].value;

	if (next_case == FREE || next_case == SLOT) {
		free_moove(&(board[i[NEW_X]][i[NEW_Y]]),
		&(board[i[EX_X]][i[EX_Y]]));
		(*g_i)->player_pos = new_cells[FI_NEIGHBOUR];
		free(i);
		return (SUCCESS);
	}
	if (next_case == BOX || next_case == BOX_ONSLOT) {
		if (!moove_box(&(board[i[EX_X]][i[EX_Y]]),
		&(board[i[NEW_X]][i[NEW_Y]]),
		&(board[i[S_NEW_X]][i[S_NEW_Y]]), &(*g_i)))
			return (ERROR);
		(*g_i)->player_pos = new_cells[FI_NEIGHBOUR];
		free(i);
		return (SUCCESS);
	}
	free(i);
	return (ERROR);
}

int	key_pressed(int pos, t_cell **board, t_game_info **game_info)
{
	int	ch = getch();
	int	*concerned_cells = NULL;

	if (IS_ARROW_KEY(ch))
		concerned_cells = arrows_pressed(ch, pos, (*game_info)->x_map);
	if (action(concerned_cells, pos, board, &(*game_info)) != SUCCESS) {
		free(concerned_cells);
		return (ERROR);
	}
	free(concerned_cells);
	return (SUCCESS);
}

void	update_ui(t_cell **board, t_game_info **g_info)
{
	clear();
	display_game(*g_info, board);
	refresh();
}

void	init_ncurse()
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
}

int	game_loop(t_game_info *g_info, t_cell **board)
{
	int	i = 1;

	init_ncurse();
	display_game(g_info, board);
	refresh();
	while (i) {
		if (key_pressed(g_info->player_pos, &(*board), &g_info)) {
			update_ui(board, &g_info);
		}
		if (g_info->slot_nbr == g_info->slot_ok)
			i = 0;
	}
	endwin();
	return (SUCCESS);
}
