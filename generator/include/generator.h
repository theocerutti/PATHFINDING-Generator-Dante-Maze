/*
** EPITECH PROJECT, 2019
** LIB
** File description:
** LIB
*/

#include "lib.h"

void print_maze(maze_t *maze);
void generate_maze(maze_t *maze);
void make_imperfect_maze(maze_t *maze);
void cleanup(maze_t *maze);
cell_t get_rand_neightbours(maze_t *maze, cell_t random_cell);
int is_no_longer_cell_visited(maze_t *maze);
int have_current_cell_neighbours(maze_t *maze, cell_t current);
void last_check(list_t wall_list, maze_t *maze);
int randomize(int a, int b);