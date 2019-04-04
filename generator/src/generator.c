/*
** EPITECH PROJECT, 2019
** generator perfect maze
** File description:
** generator perfect maze
*/

#include "../include/generator.h"

int pick_rand_wall(list_t wall_list, cell_t *rand_wall, int size_list)
{
    node_t *tmp = wall_list;
    int nb_rand = 0;

    if (size_list != 0) {
        nb_rand = (rand() % (size_list));
    }
    for (int i = 0; i < nb_rand; i++) {
        tmp = tmp->next;
    }
    rand_wall->x = tmp->cell.x;
    rand_wall->y = tmp->cell.y;
    return (nb_rand);
}

cell_t can_make_passage(cell_t rand_wall, maze_t *m)
{
    int x = rand_wall.x;
    int y = rand_wall.y;
    cell_t ref_cell = {-1, -1};

    if (x - 1 >= 0 && x + 1 < m->width && m->maze[y][x - 1] == '*'
    && m->maze[y][x + 1] != '*')
        ref_cell = (cell_t){x - 1, y};
    else if (x - 1 >= 0 && x + 1 < m->width && m->maze[y][x + 1] == '*'
    && m->maze[y][x - 1] != '*')
        ref_cell = (cell_t){x + 1, y};
    if (y - 1 >= 0 && y + 1 < m->height && m->maze[y + 1][x] == '*'
    && m->maze[y - 1][x] != '*')
        ref_cell = (cell_t){x, y + 1};
    else if (y - 1 >= 0 && y + 1 < m->height && m->maze[y - 1][x] == '*'
    && m->maze[y + 1][x] != '*')
        ref_cell = (cell_t){x, y - 1};
    return (ref_cell);
}

cell_t mark_maze(maze_t *m, cell_t rand_wall, cell_t ref_cell)
{
    int x_opp = 2 * rand_wall.x - ref_cell.x;
    int y_opp = 2 * rand_wall.y - ref_cell.y;
    cell_t opp_cell = {x_opp, y_opp};

    m->maze[rand_wall.y][rand_wall.x] = '*';
    if (opp_cell.y >= 0 && opp_cell.y < m->height
    && opp_cell.x >= 0 && opp_cell.x < m->width)
        m->maze[opp_cell.y][opp_cell.x] = '*';
    return (opp_cell);
}

void add_unvisited_neightbours_list(maze_t *m, cell_t opp_cell, list_t list)
{
    int x = opp_cell.x;
    int y = opp_cell.y;

    if (x - 1 >= 0 && m->maze[y][x - 1] == 'X') {
        list = push(list, (cell_t){x - 1, y});
        m->size_list += 1;
    }
    if (x + 1 < m->width && m->maze[y][x + 1] == 'X') {
        list = push(list, (cell_t){x + 1, y});
        m->size_list += 1;
    }
    if (y + 1 < m->height && m->maze[y + 1][x] == 'X') {
        list = push(list, (cell_t){x, y + 1});
        m->size_list += 1;
    }
    if (y - 1 >= 0 && m->maze[y - 1][x] == 'X') {
        list = push(list, (cell_t){x, y - 1});
        m->size_list += 1;
    }
}

void generate_maze(maze_t *maze)
{
    int pos_rand_wall = 0;
    list_t wall_list = NULL;
    cell_t ref_cell = {-1, -1};
    cell_t rand_wall = {-1, -1};
    cell_t opp_cell = {-1, -1};

    maze->maze[0][0] = '*';
    wall_list = push(wall_list, (cell_t){0, 1});
    wall_list = push(wall_list, (cell_t){1, 0});
    maze->size_list = 2;
    while (!is_empty(wall_list)) {
        pos_rand_wall = pick_rand_wall(wall_list, &rand_wall, maze->size_list);
        if ((ref_cell = can_make_passage(rand_wall, maze)).x != - 1) {
            opp_cell = mark_maze(maze, rand_wall, ref_cell);
            add_unvisited_neightbours_list(maze, opp_cell, wall_list);
        }
        wall_list = pop_index(wall_list, pos_rand_wall);
        maze->size_list -= 1;
    }
    last_check(wall_list, maze);
}