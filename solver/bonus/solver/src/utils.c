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

void get_color(char c)
{
    switch (c) {
        case '_':
            attron(COLOR_PAIR(SECOND_WAY));
            break;
        case 'o':
            attron(COLOR_PAIR(MAIN_WAY));
            break;
        case '*':
            attron(COLOR_PAIR(PATH));
            break;
        case 'X':
            attron(COLOR_PAIR(WALL));
            break;
        case -1:
            attron(COLOR_PAIR(START));
            break;
        case -2:
            attron(COLOR_PAIR(END));
    }
}

void print_character_with_color(maze_t *maze, int i, int j)
{
    char c = maze->maze[i][j];

    c = (i == 0 && j == 0) ? -1 : maze->maze[i][j];
    if (c != -1)
        c = (i == maze->height && j == maze->width) ? -2 :
        maze->maze[i][j];
    get_color(c);
    mvaddch(i, j, maze->maze[i][j]);
    usleep(1000);
    refresh();
}

void print_maze(maze_t *maze)
{
    for (int i = 0; maze->maze[i] != NULL; i++) {
        for (int j = 0; maze->maze[i][j] != '\0'; j++) {
            if (maze->maze[i][j] == 'X') {
                attron(COLOR_PAIR(WALL));
            } else if (maze->maze[i][j] == '*') {
                attron(COLOR_PAIR(PATH));
            }
            mvaddch(i, j, maze->maze[i][j]);
        }
    }
    refresh();
}