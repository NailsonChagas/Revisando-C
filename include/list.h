#ifndef LIST_H
#define LIST_H

#include <cell.h>

typedef struct list {
    Cell *head;
    int length;
} List;

List *create_list(void);
void list_insert(List *list, Cell *new);
void list_insert_at_idx(List *list, Cell *new, int index);
void list_swap_cell(List *list, int indexA, int indexB);
Cell *list_get_idx(List *list, int index);
void list_remove(List *list, int index);
void clear_list(List *list);
void free_list(List *list);
void print_list(List *list);
#endif