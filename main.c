#include <stdio.h>
#include <cell.h>

int main(void){
    int value = 42;
    char *str = "Hello, World!";
    Cell *int_cell = create_cell(&value, INT);
    Cell *str_cell = create_cell(str, STRING);
    Cell *void_cell = create_cell(str, VOID);

    print_cell(int_cell);
    print_cell(str_cell);
    print_cell(void_cell);

    return 0;
}