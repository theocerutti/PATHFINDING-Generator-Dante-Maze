/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generator
*/

#include "../include/generator.h"

void write_in_file(maze_t *maze)
{
    FILE *file = fopen("map_output", "w");

    for (int i = 0; maze->maze[i] != NULL; i++) {
        fprintf(file, "%s", maze->maze[i]);
        if (maze->maze[i + 1] != NULL)
            fprintf(file, "\n");
    }
    fclose(file);
}