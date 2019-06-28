/*
** EPITECH PROJECT, 2018
** my_exec.c
** File description:
** minishell1
*/

#include	<ncurses.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"sokoban.h"
#include	"utils.h"
#include	"map.h"
#include	"string.h"

int	get_map_limit(const char *name, int **limits, char ***first_board)
{
	char	*line = NULL;
	int	i = 0;
	FILE	*stream = fopen(name, "r");
	size_t	lenght = 0;
	ssize_t	nread;

	if (stream == NULL || limits == NULL || !first_board)
		return (ERROR);
	while ((nread  = getline(&line, &lenght, stream)) != -1) {
		(*first_board)[i] = my_strdup(line);
		if (nread > (*limits)[COLUMN]) {
			(*limits)[COLUMN] = nread;
			if (line[(*limits)[COLUMN] - 1] == SPACE)
				(*limits)[COLUMN]--;
		}
		i++;
		(*limits)[LINE]++;
	}
	free(line);
	fclose(stream);
	return (SUCCESS);
}

int	init_data(const char *name, t_game_info **game_info)
{
	int	*map_info = malloc(sizeof(int) * 2);
	char	**first_board = malloc(sizeof(char *) *
	get_file_line_nbr(name) + 1);

	if (!name || !map_info || !first_board)
		return (ERROR);
	map_info[0] = 0;
	map_info[1] = 0;
	if (get_map_limit(name, &map_info, &first_board) == ERROR)
		return (ERROR);
	(*game_info)->slot_nbr = 0;
	(*game_info)->slot_ok = 0;
	(*game_info)->x_map = map_info[0];
	(*game_info)->y_map = map_info[1];
	(*game_info)->first_board = first_board;
	free(map_info);
	return (SUCCESS);
}
