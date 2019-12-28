#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

void mx_test_err(int argc, char *file, char **argv);
void mx_printerr(const char *s);
void mx_parse(char *fd, int ***matrix, char ***set);
int **mx_create_matrix(char **set, char ***arrarr);
void mx_print_matrix(int **matrix, char **set);
void mx_algoritm(int **matrix, char **set);
void mx_printerr_exit(const char *s);
void mx_check_spaces(char **src, char *file);
void mx_create_arr(char **src, char ***arrarr);
void mx_create_set(char ***set, char ***arrarr, char *numOfIsland);
void mx_delMat(int ***matrix, char **set);

typedef struct s_path {
    int idPath;
    int distPath;
    struct s_path *nextConnect;
    struct s_path *nextPath;
}		t_path;

typedef struct s_island {
    int indexIslnd;
    int distTo;
    struct s_path *path;
    struct s_island *next;
}		t_island;

typedef struct s_char {
	char *p;
	char *r;
	char *d;
	int s;
}		t_char;

t_island *mx_short_dist(t_island **unvisited);
t_path *mx_create_path(int isl, int dist);
void mx_push_backPath(t_path **path, t_path **previous, int isl, int dist);void mx_addLink(t_path **cur, t_path **new);
t_path *mx_addPath(t_path **previous, int isl, int dist);
void mx_delPath(t_path **head);
t_path *mx_copyPath(t_path **data);
int mx_uniquePath(t_path **new, t_path **pre);
void mx_join(char **res, char *s2);
void mx_printOutput(t_island **visited, int root, int size, char **set);
void mx_addLink(t_path **cur, t_path **new);
t_path *mx_addOnePath(t_path **previous, int isl, int dist);
t_island *mx_create_island(int isl, int dist);
void mx_push_back_island(t_island **island, t_path **path, int isl, int dist);
void mx_pop_front_island(t_island **head);
void mx_pop_middle_island(t_island **unvisited, int index);

#endif
