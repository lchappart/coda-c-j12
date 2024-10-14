#ifndef EX_2
#define EX_2

#include <stdlib.h>
#include <stdio.h>

typedef struct s_number number;

struct s_number {
    int value;
    number *next;
};

void add_to_end(number **list);

#endif