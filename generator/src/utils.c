/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generator
*/

#include "../include/generator.h"

void cleanup(maze_t *maze)
{
    for (int i = 0; i < maze->height + 1; i++) {
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

void last_check(list_t wall_list, maze_t *maze)
{
    if (maze->height - 1 >= 0 && maze->width - 1 >= 0 &&
    maze->maze[maze->height - 1][maze->width - 1] != '*') {
        maze->maze[maze->height - 1][maze->width - 1] = '*';
        if (maze->height - 2 >= 0 && maze->width - 2 >= 0 &&
        maze->maze[maze->height - 2][maze->width - 2] == '*' &&
        maze->maze[maze->height - 1][maze->width - 2] != '*')
            maze->maze[maze->height - 2][maze->width - 1] = '*';
        else if (maze->height - 2 >= 0 && maze->width - 2 >= 0 &&
        maze->maze[maze->height - 2][maze->width - 2] != '*') {
            maze->maze[maze->height - 2][maze->width - 1] = '*';
            maze->maze[maze->height - 1][maze->width - 2] = '*';
        }
    }
    delete_list(wall_list);
}