/*
** EPITECH PROJECT, 2018
** Dante
** File description:
** Generator header
*/

#ifndef SOKOBAN_H_
	#define SOKOBAN_H_

#include	<ncurses.h>
#include	"map.h"

#define		IS_CORRECT_CELL(c)	(c != 0 && c != 10 ? 1 : 0)
#define		IS_ARROW_KEY(c)		(c == KEY_UP ||\
c == KEY_RIGHT ||\
c == KEY_DOWN || c == KEY_LEFT ? 1 : 0)

typedef	struct s_game_info	t_game_info;
static const int			EXITSUCCESS = 1;
static const int			EXITFAILURE = 84;
static const char			SPACE = 10;
static const int			X = 0;
static const int			Y = 1;
static const char			PLAYER_SYMBOL = 'P';
static const char			BOX_SYMBOL = 'X';
static const char			SLOT_SYMBOL = 'O';

enum		ret_state {
	ERROR = 0,
	SUCCESS
};

struct s_game_info
{
	int x_map;
	int y_map;
	int slot_nbr;
	int slot_ok;
	char **first_board;
	int player_pos;
};

int	main(int, char **);
int	init_data(const char *, t_game_info **);
int	parse_map(t_cell ***, t_game_info **, int, int);
int	*get_neighbour_infos(int *, int, int);
int	free_moove (t_cell *, t_cell *);
int	moove_box(t_cell *, t_cell *, t_cell *, t_game_info **);
int	*arrows_pressed(int, int, int);
void	destroy_settings(t_game_info *, t_cell**);
int	game_loop(t_game_info *, t_cell **);
int	display_game(t_game_info *, t_cell **);

#endif
