#include "pathfinder.h"
// ??? 5 elementov
static void fill(char **arrarr, char **set, int ***matrix, int i, int j) {
    int **mat = *matrix;
    int k = 0;

    if (mx_isdigit(arrarr[j + 1][0]) != 1) {
        k = 0;
        while(mx_strcmp(arrarr[j + 1], set[k]) != 0) 
            k++;
        mat[i][k] = mx_atoi(arrarr[j + 2]);
    }
    else {
        k = 0;
        while(mx_strcmp(arrarr[j - 1], set[k]) != 0) 
            k++;
        mat[i][k] = mx_atoi(arrarr[j + 1]);
    } 
} // 14

static void mx_matrix_algoritm(char **arrarr, char **set, int ***matrix) {
    int i = 0;
    int j = 0;
    
    while (set[i]) {
        j = 0;
        while(arrarr[j]) {
            if (mx_strcmp(set[i], arrarr[j]) == 0) { 
                fill(arrarr, set, &(*matrix), i, j);
            }
            j++;
        }
        i++;
    }
} // 12

int **mx_matrix(char ***arrarr, char **set) {
    int **matrix = NULL;
    int i = 0;
    int k = 0;

    while(set[i]) 
        i++;
    matrix = malloc(sizeof(int*) * i);
    k = i;
    while(k >= 0) { 
        matrix[k] = malloc(sizeof(int) * i);
        k--;
    }
    mx_matrix_algoritm(*arrarr, set, &matrix);
    return matrix;
} // 13
