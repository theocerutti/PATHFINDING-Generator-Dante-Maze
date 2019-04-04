/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generator
*/

#include "../include/generator.h"

void print_case_color(int i, int j, char c)
{
    mvaddch(i, j, c);
    usleep(1000);
    refresh();
}

void print_character_with_color(maze_t *maze, int i, int j)
{
    char c = maze->maze[i][j];

    c = (i == 0 && j == 0) ? -1 : maze->maze[i][j];
    if (c != -1)
        c = (i == maze->height - 1 && j == maze->width - 1) ? -2 :
        maze->maze[i][j];
    switch (c) {
        case -2:
            attron(COLOR_PAIR(END));
            break;
        case -1:
            attron(COLOR_PAIR(START));
            break;
        case '*':
            attron(COLOR_PAIR(PATH));
            break;
        case 'X':
            attron(COLOR_PAIR(WALL));
    }
    print_case_color(i, j, maze->maze[i][j]);
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