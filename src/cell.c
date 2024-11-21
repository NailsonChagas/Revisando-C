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

void print_cell(Cell *cell){
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
        case VOID:
            printf("Data: ");
            unsigned char *ptr = (unsigned char *)cell->data;
            //apenas os 16 primeiros bytes
            for (int i = 0; i < 16; ++i) { 
                printf("%02X ", ptr[i]);
            }
            printf("\n");
            break;
    }
    printf("Next: %p \t Previous: %p\n", cell->next, cell->previous);
    printf("--------------------------------\n");
}