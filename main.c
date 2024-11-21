#include <string.h>
#include <stdio.h>
#include <cell.h>

int main(void){
    int value = 42;
    char *str = "Hello, World!";
    Cell *int_cell = create_cell(&value, INT);
    Cell *str_cell = create_cell(str, STRING);
    Cell *void_cell = create_cell(str, VOID);
    Cell *void_malloc_cell = create_cell(strdup(str), VOID_MALLOC);

    print_cell(int_cell);
    print_cell(str_cell);
    print_cell(void_cell);
    print_cell(void_malloc_cell);

    free_cell(int_cell);
    free_cell(str_cell);
    free_cell(void_cell);
    free_cell(void_malloc_cell);

    return 0;
}