# sokoban_epitech (TECH 1 2017-2018)

The goal of this project is to develop a copy of Sokoban game in terminal mode, using the ncurses library.

https://fr.wikipedia.org/wiki/Sokoban

- If all boxes are on storage locations, the player wins and the program must return 0.
- Otherwise, if none of the boxes can be moved anymore, he loses and the program must return 1.
- The game must be reset by pressing the space bar.
- Redimensioning the terminal must be handled. As long as the terminal is too small to display the whole
map, a centered message, asking the user to enlarge the terminal, must be displayed.
- The game must be able to be played with the arrow keys (LEFT, RIGHT, UP and DOWN).
- A valid map can only contains the characters SPACE, ‘\n’, ‘#’, ‘X’, ‘O’ and ‘P’.
- If an invalid map is supplied, the program must exit with an error.

to build:
    
    make / make re

USAGE

    ./my_sokoban map
    
DESCRIPTION
    
    map file representing the warehouse map, containing ‘#’ for walls, ‘P’ for the player, ‘X’ for boxes and ‘O’ for storage locations.

Aymeric Astaing - EPITECH PARIS PROMO 2022
