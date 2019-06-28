/*
** EPITECH PROJECT, 2018
** my_exec.c
** File description:
** minishell1
*/

#include	<stdlib.h>
#include	"sokoban.h"
#include	"map.h"
#include	"utils.h"

void		destroy_settings(t_game_info *game_info, t_cell **board)
{
	int	i = 0;

	while (i < game_info->y_map) {
		free(game_info->first_board[i]);
		free(board[i]);
		i++;
	}
	free(board);
	free(game_info->first_board);
	free(game_info);
}
