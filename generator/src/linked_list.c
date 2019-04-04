/*
** EPITECH PROJECT, 2018
** Handle linked_list
** File description:
** Handle linked_list
*/

#include "../include/generator.h"

list_t delete_list(list_t list)
{
    node_t *temp = NULL;

    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
    return (NULL);
}

list_t push(list_t list, cell_t new_cell)
{
    node_t *temp = list;
    node_t *new_node = malloc(sizeof(node_t));

    new_node->cell = new_cell;
    new_node->next = NULL;
    if (is_empty(list))
        return (new_node);
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    return (list);
}

list_t push_index(list_t list, cell_t new_cell, int n)
{
    int i = 0;
    node_t *current = list;
    node_t *temp_node = NULL;
    node_t *new_node = malloc(sizeof(node_t));

    new_node->cell = new_cell;
    if (is_empty(list))
        return (new_node);
    if (n == 0) {
        temp_node = current;
        new_node->next = current;
        return (new_node);
    }
    for (i = 0; i < n - 1 && current->next != NULL; i++)
        current = current->next;
    temp_node = current->next;
    current->next = new_node;
    new_node->next = temp_node;
    return (list);
}

list_t pop_index(list_t list, int n)
{
    int i = 0;
    node_t *current = list;
    node_t *temp_node = NULL;

    if (is_empty(list))
        return (NULL);
    if (n == 0) {
        list = list->next;
        return (list);
    }
    for (i = 0; i < n - 1; i++) {
        if (current->next == NULL)
            return (list);
        current = current->next;
    }
    temp_node = current->next;
    current->next = temp_node->next;
    free(temp_node);
    return (list);
}

int is_empty(list_t list)
{
    if (list == NULL) {
        return (1);
    } else
        return (0);
}
