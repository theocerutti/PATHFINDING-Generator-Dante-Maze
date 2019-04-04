/*
** EPITECH PROJECT, 2019
** solver using A*
** File description:
** solver using A*
*/

#include "../include/solver.h"

int get_size_list(list_t list)
{
    int size = 0;
    node_t *tmp = list;

    while (tmp != NULL) {
        size += 1;
        tmp = tmp->next;
    }
    return (size);
}

tab_t fill_tab_list(list_t list)
{
    int size_list = get_size_list(list);
    tab_t tab = {NULL, size_list};
    node_t *tmp = list;

    if (size_list != 0)
        size_list -= 1;
    tab.cell = malloc(sizeof(cell_t) * (tab.size));
    for (int i = size_list; i >= 0; i--) {
        tab.cell[i] = tmp->cell;
        tmp = tmp->next;
    }
    return (tab);
}

int is_neightbours(cell_t before, cell_t current)
{
    if ((current.y + 1 == before.y && current.x == before.x) ||
    (current.y - 1 == before.y && current.x == before.x) ||
    (current.y == before.y && current.x + 1 == before.x) ||
    (current.y == before.y && current.x - 1 == before.x) ||
    (current.y == before.y && current.x == before.x))
        return (1);
    return (0);
}

void draw_main_path(maze_t *maze, list_t list)
{
    tab_t pos = fill_tab_list(list);
    cell_t before = pos.cell[0];
    cell_t current;
    cell_t good = {0, 0, 0, 0};
    int i = 0;

    for (i = 0; pos.cell[i].x != 0 || pos.cell[i].y != 0; i++);
    for (int e = i; i != pos.size + e; i++) {
        current = pos.cell[i];
        if (is_neightbours(before, current) == 1) {
            good = pos.cell[i];
        }
        before = good;
        maze->maze[good.y][good.x] = 'o';
    }
}