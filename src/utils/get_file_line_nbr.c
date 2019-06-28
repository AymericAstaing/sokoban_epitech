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

int	get_file_line_nbr(const char *name)
{
	char	*line = NULL;
	int	line_nbr = 0;
	FILE	*stream = fopen(name, "r");
	size_t	len = 0;
	ssize_t	nread;

	if (!name || !stream)
		return (ERROR);
	while ((nread  = getline(&line, &len, stream)) != -1)
		line_nbr++;
	free(line);
	fclose(stream);
	return (line_nbr);
}
