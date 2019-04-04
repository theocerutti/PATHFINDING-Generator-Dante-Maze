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

void last_check(list_t wall_list, maze_t *m)
{
    if (m->height - 1 >= 0 && m->width - 1 >= 0 &&
    m->maze[m->height - 1][m->width - 1] != '*') {
        m->maze[m->height - 1][m->width - 1] = '*';
        print_character_with_color(m, m->height - 1, m->width - 1);
        if (m->height - 2 >= 0 && m->width - 2 >= 0 &&
        m->maze[m->height - 2][m->width - 2] == '*' &&
        m->maze[m->height - 1][m->width - 2] != '*') {
            m->maze[m->height - 2][m->width - 1] = '*';
            print_character_with_color(m, m->height - 2, m->width - 1);
        } else if (m->height - 2 >= 0 && m->width - 2 >= 0 &&
        m->maze[m->height - 2][m->width - 2] != '*') {
            m->maze[m->height - 2][m->width - 1] = '*';
            print_character_with_color(m, m->height - 2, m->width - 1);
            m->maze[m->height - 1][m->width - 2] = '*';
            print_character_with_color(m, m->height - 1, m->width - 2);
        }
    }
    delete_list(wall_list);
}