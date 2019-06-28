/*
** EPITECH PROJECT, 2018
** my_exec.c
** File description:
** minishell1
*/

#include	<ncurses.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"sokoban.h"
#include	"map.h"
#include	"utils.h"

char	*get_char_value(int value)
{
	switch (value) {
		case WALL:
			return ("#");
		case BOX:
			return ("X");
		case FREE:
			return (" ");
		case SLOT:
			return ("O");
		case PLAYER:
			return ("P");
		case PLAYER_ONSLOT:
			return ("P");
		case BOX_ONSLOT:
			return ("X");
	}
	return ("\0");
}

int	display_game(t_game_info *info, t_cell **board)
{
	int	screen_x = 0;
	int	screen_y = 0;
	int	x_pos = 0;
	int	y_pos = 0;
	char	*disp_value = malloc(sizeof(char) * 1);

	if (!disp_value)
		return (ERROR);
	getmaxyx(stdscr, screen_x, screen_y);
	if (info->x_map > (screen_x - 2) || info->y_map > (screen_y - 2))
		return (ERROR);
	x_pos = ((screen_x / 2) - (info->x_map / 2));
	y_pos = ((screen_y / 2) - (info->y_map / 2));
	for (int i = 0; i < info->y_map; i++) {
		for (int j = 0; j < info->x_map; j++) {
			disp_value = get_char_value((board[i][j]).value);
			if (disp_value[0] != '\0')
				mvprintw((i + x_pos), (j + y_pos), disp_value);
		}
	}
	return (SUCCESS);
}
