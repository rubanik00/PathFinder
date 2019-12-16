#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

void mx_test_err(int argc, char *src[]);
void mx_printerr(const char *s);
void mx_parse(char *argv);
int **mx_matrix(char ***arrarr, char **set);
void mx_print_matrix(int **matrix, char **set);
void mx_main_algoritm (int **matrix, char **set);
void mx_printerr_exit(const char *s);
void mx_check_spaces(char **src, char *file);
int mx_count_island(char **arr, char *numOfIsland);
void mx_create_arr(char **src, char ***arrarr);
void mx_create_set(char ***set, char ***arrarr, char *numOfIsland);

typedef struct s_island {
    int indexIslnd;
    int distTo;
    struct s_island * next;
} t_island;

typedef struct s_fill_island {
    char *island1;
    char *island2; 
    char *distance;
    struct s_fill_island * next;
} t_fill_island;

t_island *mx_short_dist(t_island **unvisited);
t_island *mx_create_island (int isl, int dist);
void mx_push_back_island (t_island **island, int isl, int dist);
void mx_pop_front_island(t_island **head);
void mx_pop_index (t_island **unvisited, int index);

#endif
