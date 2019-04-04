/*
** EPITECH PROJECT, 2019
** lib
** File description:
** Header struct.h
*/

enum color_block {
    WALL = 1,
    PATH = 2,
    SECOND_WAY = 3,
    MAIN_WAY = 4,
    START = 5,
    END = 6
};

typedef struct cell_s {
    int x;
    int y;
    int counter;
    int is_sup;
} cell_t;

typedef struct tab_s {
    cell_t *cell;
    int size;
} tab_t;

typedef struct maze_s {
    char **maze;
    int height;
    int width;
} maze_t;