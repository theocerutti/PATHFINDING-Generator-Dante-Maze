/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generator
*/

#include "include/generator.h"

void fill_maze(maze_t *maze)
{
    int i = 0;
    int j = 0;

    maze->maze = malloc(sizeof(char *) * (maze->height + 1));
    for (i = 0; i < maze->height; i++) {
        maze->maze[i] = malloc(sizeof(char) * (maze->width + 1));
        for (j = 0; j < maze->width; j++) {
            maze->maze[i][j] = 'X';
        }
        maze->maze[i][j] = '\0';
    }
    maze->maze[i] = NULL;
}

void check_error(int ac, char *av[])
{
    if (ac != 3 && ac != 4)
        exit(84);
    for (int i = 0; av[1][i] != '\0'; i++)
        if (av[1][i] < '0' || av[1][i] > '9')
            exit(84);
    for (int i = 0; av[2][i] != '\0'; i++)
        if (av[2][i] < '0' || av[2][i] > '9')
            exit(84);
    if (atoi(av[1]) <= 0 || atoi(av[2]) <= 0)
        exit(84);
    if (ac == 4)
        if (strncmp(av[3], "perfect", 8))
            exit(84);
}

void init_color_curse(void)
{
    assume_default_colors(COLOR_YELLOW, COLOR_YELLOW);
    init_pair(WALL, COLOR_BLACK, COLOR_BLACK);
    init_pair(PATH, COLOR_WHITE, COLOR_WHITE);
    init_pair(START, COLOR_GREEN, COLOR_GREEN);
    init_pair(END, COLOR_RED, COLOR_RED);
}

void gen_loop(maze_t *maze)
{
    init_color_curse();
    fill_maze(maze);
    print_maze(maze);
    generate_maze(maze);
    if (maze->is_perfect == FALSE) {
        make_imperfect_maze(maze);
    }
    getch();
    endwin();
    write_in_file(maze);
    cleanup(maze);
}

int main(int ac, char **av)
{
    maze_t maze = {NULL, 0, 0, 0, 2};

    initscr();
    start_color();
    curs_set(0);
    srand(time(NULL));
    check_error(ac, av);
    maze.width = atoi(av[1]);
    maze.height = atoi(av[2]);
    if (ac == 4 && !strncmp(av[3], "perfect", 8))
        maze.is_perfect = TRUE;
    else
        maze.is_perfect = FALSE;
    gen_loop(&maze);
    return (0);
}