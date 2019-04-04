/*
** EPITECH PROJECT, 2018
** stack header
** File description:
** stack header
*/

typedef struct node_s {
    cell_t cell;
    struct node_s *next;
} node_t;
typedef node_t *list_t;

list_t delete_list(list_t list);
list_t push(list_t list, cell_t new_cell);
list_t push_index(list_t list, cell_t new_cell, int n);
list_t pop_index(list_t list, int n);
void print_list(list_t list);
int is_empty(list_t list);