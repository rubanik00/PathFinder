#include "pathfinder.h"

void mx_parse(char *fd, int ***matrix, char ***set) {
    char **arrarr = NULL;
    char **src = mx_strsplit(fd, '\n');

    mx_create_arr(src, &arrarr);
    mx_create_set(&(*set), &arrarr, src[0]);
    *matrix = mx_create_matrix(*set, &arrarr);
    mx_del_strarr(&src);
    mx_del_strarr(&arrarr);
}
