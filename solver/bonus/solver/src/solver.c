/*
** EPITECH PROJECT, 2019
** solver using A*
** File description:
** solver using A*
*/

#include "../include/solver.h"

cell_t *get_neightbours(cell_t ref_cell)
{
    cell_t *neightbours = malloc(sizeof(cell_t) * 4);
    int x = ref_cell.x;
    int y = ref_cell.y;
    int counter = ref_cell.counter;

    for (int i = 0; i < 4; i++) {
        neightbours[i].counter = counter + 1;
        neightbours[i].is_sup = 0;
    }
    neightbours[0].x = x + 1;
    neightbours[0].y = y;
    neightbours[1].x = x;
    neightbours[1].y = y + 1;
    neightbours[2].x = x - 1;
    neightbours[2].y = y;
    neightbours[3].x = x;
    neightbours[3].y = y - 1;
    return (neightbours);
}

void look_neightbours(list_t list, maze_t *maze, cell_t *neight)
{
    node_t *tmp = list;
    int x = 0;
    int y = 0;

    for (int i = 0; i < 4; i++) {
        if ((neight[i].x > maze->width || neight[i].x < 0) ||
        (neight[i].y > maze->height || neight[i].y < 0))
            neight[i].is_sup = -1;
        x = neight[i].x;
        y = neight[i].y;
        if (neight[i].is_sup != -1 && maze->maze[y][x] == 'X')
            neight[i].is_sup = -1;
        tmp = list;
        while (tmp != NULL) {
            if (tmp->cell.x == x && tmp->cell.y == y &&
            tmp->cell.counter <= neight[i].counter)
                neight[i].is_sup = -1;
            tmp = tmp->next;
        }
    }
}

list_t add_tab_to_list(list_t list, cell_t *neightbours)
{
    for (int i = 0; i < 4; i++) {
        if (neightbours[i].is_sup != -1)
            list = push(list, neightbours[i]);
    }
    return (list);
}

void solve_maze(maze_t *maze)
{
    list_t list = NULL;
    node_t *tmp = NULL;
    cell_t *neightbours = NULL;

    print_maze(maze);
    list = push(list, (cell_t){maze->width, maze->height, 0, 0});
    tmp = list;
    do {
        neightbours = get_neightbours(tmp->cell);
        look_neightbours(list, maze, neightbours);
        list = add_tab_to_list(list, neightbours);
        if (tmp->cell.x == 0 && tmp->cell.y == 0)
            break;
        tmp = tmp->next;
    } while (tmp != NULL);
    draw_secondary_path(maze, list);
    draw_main_path(maze, list);
    delete_list(list);
}