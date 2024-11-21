#include <cell.h>
#include <stdio.h>
#include <stdlib.h>

Cell* create_cell(void *data, DataType type){
    Cell *new = (Cell*)malloc(sizeof(Cell));

    new->type = type;
    new->data = data;
    new->next = NULL; 
    new->previous = NULL;

    return new;
}

void free_cell(Cell *cell){
    if (cell->type == VOID_MALLOC) {
        free(cell->data);
    }
    free(cell);
}

void print_cell(Cell *cell){
    printf("Current: %p / ", cell);
    switch (cell->type){
        case INT:
            printf("Data: %d\n", *(int *)(cell->data));
            break;
        case FLOAT:
            printf("Data: %f\n", *(float *)(cell->data));
            break;
        case STRING:
            printf("Data: %s\n", (char *)(cell->data));
            break;
        case VOID: //apenas os 16 primeiros bytes para legibilidade
        case VOID_MALLOC:
            printf("Data: ");
            unsigned char *ptr = (unsigned char *)cell->data;
            for (int i = 0; i < 16; ++i) { 
                printf("%02X ", ptr[i]);
            }
            printf("\n");
            break;
    }
    printf("Previous: %p / Next: %p\n", cell->previous, cell->next);
    printf("-------------------------------------------------------------------------------\n");
}