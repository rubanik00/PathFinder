#include "pathfinder.h"

void mx_print_matrix(int **matrix, char **set) {
    int i = 0, k = 0;
    while(set[i]) i++;
    while(k < i) {
        int j = 0;
        while (j < i) {
            mx_printint(matrix[k][j]);
            mx_printchar(' ');
            j++;
        }
        mx_printchar('\n');
        k++;
    }
} // 13
