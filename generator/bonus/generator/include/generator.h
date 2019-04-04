/*
** EPITECH PROJECT, 2019
** LIB
** File description:
** LIB
*/

#include "lib.h"

void print_character_with_color(maze_t *maze, int i, int j);
void generate_maze(maze_t *maze);
void make_imperfect_maze(maze_t *maze);
void cleanup(maze_t *maze);
cell_t get_rand_neightbours(maze_t *maze, cell_t random_cell);
int is_no_longer_cell_visited(maze_t *maze);
int have_current_cell_neighbours(maze_t *maze, cell_t current);
int randomize(int a, int b);
void last_check(list_t wall_list, maze_t *maze);
void print_maze(maze_t *maze);
void write_in_file(maze_t *maze);