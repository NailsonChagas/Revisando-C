#include <stdlib.h>
#include <stdio.h>
#include <list.h>

List *create_list(void){
    List *new = (List*)malloc(sizeof(List));
    new->head = NULL;
    new->length = 0;
    
    return new;
}

void list_insert(List *list, Cell *new){
    if (list->head == NULL) {
        list->head = new;
    } else {
        Cell *aux = list->head;
        while (aux->next != NULL) {
            aux = aux->next;  
        }

        aux->next = new;
        new->previous = aux;  
    }
    list->length += 1;
}

void list_insert_at_idx(List *list, Cell *new, int index){
    
}

void list_swap_cell(List *list, int indexA, int indexB){

}

Cell *list_get_idx(List *list, int index){
    Cell *aux = list->head;
    int i = 0;

    while (aux != NULL) {
        if(i == index){
            return aux;
        }

        aux = aux->next;
        i += 1;
    }
    return NULL;
}

void list_remove(List *list, int index){
    Cell *aux = list->head;
    int i = 0;

    while (aux != NULL) {
        if(i == index){
            if(aux->previous != NULL){
                aux->previous->next = aux->next;
            }
            else {
                list->head = aux->next;
            }

            if (aux->next != NULL){
                aux->next->previous = aux->previous;
            }
        
            free_cell(aux);
            list->length -= 1;
            return;
        }

        aux = aux->next;
        i += 1;
    }
}

void clear_list(List *list){
    Cell *aux = list->head;

    while (aux != NULL) {
        list->head = aux->next;
        free_cell(aux);
        aux = list->head;
    }

    list->length = 0;
}

void free_list(List *list){
    clear_list(list);
    free(list);
}

void print_list(List *list){
    if(list == NULL) return;
    Cell *aux = list->head;
    int i = 0;

    printf("-------------------------------------------------------------------------------\n");
    printf("List address: %p / Head address: %p / Length: %d\n", list, list->head, list->length);
    printf("-------------------------------------------------------------------------------\n");
    while (aux != NULL) {
        printf("-> Index: [%d]\n", i);
        print_cell(aux);
        aux = aux->next;  
        i += 1;
    }
}