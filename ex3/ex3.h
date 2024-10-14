#ifndef EX_1
#define EX_1

#include <stdlib.h>
#include <stdio.h>

typedef struct s_number number;
struct s_number {
    int value;
    number *next;
};

void add_to_end(number **list, int value);
void display_list(number **list);

#endif