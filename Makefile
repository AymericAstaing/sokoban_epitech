##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## CPE_pushswap__2018
##

#	Root path
ROOT		=		./

#	Sources path
F_SRC		=		$(ROOT)src/

#	Binary name
NAME		=		my_sokoban

SRC		=		$(F_SRC)main.c

SRC		+=		$(F_SRC)utils/get_file_line_nbr.c		\
				$(F_SRC)utils/len.c						\
				$(F_SRC)utils/my_strdup.c				\
				$(F_SRC)utils/coor_to_pos.c				\
				$(F_SRC)utils/get_neighbour_infos.c		\
				$(F_SRC)utils/pos_to_coor.c				\
				$(F_SRC)utils/my_putstr.c				\
				$(F_SRC)utils/my_strcpy.c

SRC		+=		$(F_SRC)init.c							\
				$(F_SRC)event.c							\
				$(F_SRC)moove.c							\
				$(F_SRC)destroy_settings.c				\
				$(F_SRC)display.c						\
				$(F_SRC)game.c							\
				$(F_SRC)parse.c

#	Compile every source file to .o
OBJ		=		$(SRC:.c=.o)

#	Compiler
CC		=		cc -g3

#	Compilation flags
CFLAGS		+=		-Wall -Werror -Wextra -pedantic -std=gnu99	\
				-I $(ROOT)include/

#	Call compilation rule
all:				$(NAME)

#	Compile every file then pack them all !
$(NAME):			$(OBJ)
				$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS) -lncurses

#	Compile with g3 flag
debug:				fclean $(OBJ)
				$(CC) -o $(NAME) $(CFLAGS) -g3 $(OBJ) $(LDFLAGS)

#	Clean object type sources
clean:
				rm -f $(OBJ)

#	Clean binary
fclean:					clean
				rm -f $(NAME)

#	Clean all then compile
re:				fclean all

.PHONY:				all clean fclean re

