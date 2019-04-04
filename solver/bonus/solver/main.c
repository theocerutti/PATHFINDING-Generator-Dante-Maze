/*
** EPITECH PROJECT, 2019
** solver using A*
** File description:
** solver using A*
*/

#include "include/solver.h"

int check_error(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (access(av[1], F_OK) == -1 || opendir(av[1]) != NULL)
        return (84);
    return (0);
}

int check_error_maze(maze_t *m)
{
    int len = 0;
    int last_len = strlen(m->maze[0]);

    for (int i = 1; m->maze[i] != NULL; i++) {
        if (last_len != (len = strlen(m->maze[i]))) {
            return (84);
        } else
            last_len = len;
        for (int j = 0; m->maze[i][j] != '\0'; j++) {
            if (m->maze[i][j] != '*' && m->maze[i][j] != 'X') {
                return (84);
            }
        }
    }
    if (m->maze[0][0] == 'X' || m->maze[m->height][m->width] == 'X') {
        printf("no solution found\n");
        return (84);
    }
    return (0);
}

void init_color_curse(void)
{
    assume_default_colors(COLOR_YELLOW, COLOR_YELLOW);
    init_pair(WALL, COLOR_BLACK, COLOR_BLACK);
    init_pair(PATH, COLOR_WHITE, COLOR_WHITE);
    init_pair(SECOND_WAY, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(MAIN_WAY, COLOR_CYAN, COLOR_CYAN);
    init_pair(START, COLOR_GREEN, COLOR_GREEN);
    init_pair(END, COLOR_RED, COLOR_RED);
}

int main(int ac, char **av)
{
    maze_t maze = {NULL, 0, 0};

    initscr();
    start_color();
    curs_set(0);
    init_color_curse();
    if (check_error(ac, av) == 84)
        return (84);
    if (fill_maze(&maze, av[1]) == 84)
        return (84);
    if (check_error_maze(&maze) == 84)
        return (84);
    solve_maze(&maze);
    cleanup(&maze);
    getch();
    endwin();
    return (0);
}
