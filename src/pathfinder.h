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

typedef struct s_path {
    int idPath;
    int distPath;
    struct s_path *nextConnect;
    struct s_path *nextPath;
} t_path;

typedef struct s_island {
    int indexIslnd;
    int distTo;
    struct s_path *path;
    struct s_island *next;
} t_island;

t_island *mx_short_dist(t_island **unvisited);
t_island *mx_create_island (int isl, int dist);
void mx_push_back_island(t_island **island, t_path **path, int isl, int dist);
void mx_pop_front_island(t_island **head);
void mx_pop_index (t_island **unvisited, int index);
t_path *mx_create_path(int isl, int dist);
void mx_push_back_path(t_path **path, t_path **previous,int isl, int dist);
void mx_addLink(t_path **cur, t_path **new);
t_path *mx_addOnePath(t_path **previous, int isl, int dist);
t_path *mx_addPath(t_path **previous, int isl, int dist);
void mx_dellPath(t_path **head);
t_path *mx_copyPath(t_path **data);

#endif
