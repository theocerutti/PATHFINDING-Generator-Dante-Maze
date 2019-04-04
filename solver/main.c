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

int check_is_valid_maze(maze_t *maze)
{
    if (maze->maze[maze->height][maze->width] != 'o')
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    maze_t maze = {NULL, 0, 0};

    if (check_error(ac, av) == 84)
        return (84);
    if (fill_maze(&maze, av[1]) == 84)
        return (84);
    if (check_error_maze(&maze) == 84)
        return (84);
    solve_maze(&maze);
    if (check_is_valid_maze(&maze) == 84) {
        printf("no solution found\n");
        return (84);
    }
    print_maze(&maze);
    cleanup(&maze);
    return (0);
}
