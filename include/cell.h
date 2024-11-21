#ifndef CELL_H
#define CELL_H

typedef enum {
    INT,
    FLOAT,
    STRING,
    VOID,
    VOID_MALLOC // caso seja alocado dinamicamente
} DataType;

typedef struct cell {
    DataType type; 
    void *data;
    struct cell *next;
    struct cell *previous;
} Cell;

Cell* create_cell(void *data, DataType type);
void print_cell(Cell *cell);
void free_cell(Cell *cell);

#endif