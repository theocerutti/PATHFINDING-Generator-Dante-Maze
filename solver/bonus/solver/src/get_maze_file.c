/*
** EPITECH PROJECT, 2019
** get_file
** File description:
** get_file
*/

#include "../include/solver.h"

void fill_maze2(FILE *fd, maze_t *maze, int ret)
{
    char *line = NULL;
    size_t buffsize = 50;
    int i = 0;

    do {
        ret = getline(&line, &buffsize, fd);
        if (ret == -1)
            break;
        maze->maze[i] = malloc(sizeof(char) * (strlen(line) + 1));
        strcpy(maze->maze[i], line);
        if (maze->maze[i][strlen(line) - 1] == '\n')
            maze->maze[i][strlen(line) - 1] = '\0';
        i += 1;
    } while (ret != -1);
    maze->maze[i] = NULL;
    free(line);
    fclose(fd);
}

int fill_maze(maze_t *maze, char *file)
{
    FILE *fd = fopen(file, "r");
    char *line = NULL;
    size_t buffsize = 50;
    int ret = 0;

    do {
        ret = getline(&line, &buffsize, fd);
        maze->height += 1;
    } while (ret != -1);
    fclose(fd);
    maze->maze = malloc(sizeof(char *) * (maze->height + 1));
    fd = fopen(file, "r");
    fill_maze2(fd, maze, ret);
    if (maze->maze[0] == NULL)
        return (84);
    maze->width = strlen(maze->maze[0]) - 1;
    maze->height -= 2;
    return (0);
}