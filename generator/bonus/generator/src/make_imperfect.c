/*
** EPITECH PROJECT, 2019
** perfect maze to imperfect
** File description:
** perfect maze to imperfect
*/

#include "../include/generator.h"

void make_imperfect_maze(maze_t *maze)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < maze->width + maze->height; i++) {
        x = rand() % (maze->width);
        y = rand() % (maze->height);
        maze->maze[y][x] = '*';
        print_character_with_color(maze, y, x);
    }
}
