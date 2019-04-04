/*
** EPITECH PROJECT, 2019
** lib
** File description:
** Header struct.h
*/

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