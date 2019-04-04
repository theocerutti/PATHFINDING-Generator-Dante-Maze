/*
** EPITECH PROJECT, 2019
** solver_utils
** File description:
** solver utils
*/

#include "../include/solver.h"

void cleanup(maze_t *maze)
{
    for (int i = 0; i < maze->height; i++) {
        free(maze->maze[i]);
    }
    free(maze->maze);
}

void print_maze(maze_t *maze)
{
    for (int i = 0; maze->maze[i] != NULL; i++) {
        printf("%s", maze->maze[i]);
        if (maze->maze[i + 1] != NULL)
            printf("\n");
    }
}