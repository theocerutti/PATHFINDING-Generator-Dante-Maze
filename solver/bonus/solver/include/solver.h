/*
** EPITECH PROJECT, 2019
** LIB
** File description:
** LIB
*/

#include "lib.h"

void cleanup(maze_t *maze);
void print_maze(maze_t *maze);
void solve_maze(maze_t *maze);
int fill_maze(maze_t *maze, char *file);
tab_t fill_tab_list(list_t list);
void draw_main_path(maze_t *maze, list_t list);
void draw_secondary_path(maze_t *maze, list_t list);
void print_character_with_color(maze_t *maze, int i, int j);