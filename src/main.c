/*
** EPITECH PROJECT, 2018
** my_exec.c
** File description:
** minishell1
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"sokoban.h"
#include	"utils.h"
#include	"map.h"

int	main(int argc, char **argv)
{
	t_cell		**board = NULL;
	t_game_info	*game_info = malloc(sizeof(t_game_info));

	if (argc != 2 || !game_info)
		return (EXITFAILURE);
	if (init_data(argv[1], &game_info) == ERROR)
		return (EXITFAILURE);
	board = (t_cell **)malloc(sizeof(t_cell *) * (game_info->x_map));
	if (!board)
		return (EXITFAILURE);
	if (parse_map(&board, &game_info, game_info->x_map,
	game_info->y_map) == ERROR)
		return (EXITFAILURE);
	game_loop(game_info, board);
	destroy_settings(game_info, board);
	return (EXITSUCCESS);
}
