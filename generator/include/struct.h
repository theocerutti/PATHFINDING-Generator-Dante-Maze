/*
** EPITECH PROJECT, 2019
** lib
** File description:
** Header struct.h
*/

enum boolean {
    FALSE,
    TRUE
};

typedef struct cell_s {
    int x;
    int y;
} cell_t;

typedef struct maze_s {
    char **maze;
    int width;
    int height;
    int is_perfect;
    int size_list;
} maze_t;
