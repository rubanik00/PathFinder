#include "pathfinder.h"

void mx_parse(char *argv) {
    char **arrarr = NULL;
    char **set = NULL;
    int **matrix = NULL;
    char *fd = mx_file_to_str(argv);
    char **src = NULL;
    src = mx_strsplit(fd, '\n');
    mx_create_arr(src, &arrarr);
    //mx_print_strarr(arrarr, "\n"); // Print Arr
    mx_create_set(&set, &arrarr, src[0]);
    matrix = mx_matrix(&arrarr, set);
    mx_print_strarr(set, "\n"); // Print Set
    mx_print_matrix(matrix, set); //Priint Mat
    mx_main_algoritm(matrix, set); // Print Algoritm
    mx_strdel(&fd);
} // 15
