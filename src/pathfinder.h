#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

void mx_test_err(int argc, char *src[]);
void mx_printerr(const char *s);
void mx_parse(char *argv);
int **mx_matrix(char **arrarr, char **set);
void mx_print_matrix(int **matrix, char **set);
void mx_main_algoritm (int **matrix, char **set);

typedef struct s_island {
    int indexIslnd;
    int distTo;
    struct s_island * next;
} t_island;

#endif
