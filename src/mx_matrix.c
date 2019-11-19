#include "pathfinder.h"

int **mx_matrix (char **arrarr, char **set) {
    int **matrix = NULL;
    int i = 0;
    int k = 0;
    int j = 0;

    while (set[i]) i++;
    matrix = malloc (sizeof(int*) * i);
    k = i;
    while(k >= 0) { 
        matrix[k] = malloc(sizeof(int) * i);
        k--;
    }
    i = 0;
    
    while (set[i]) {
        j = 0;
        while(arrarr[j]) {
            if (mx_strcmp(set[i], arrarr[j]) == 0) { 
                if (mx_isdigit(arrarr[j + 1][0]) != 1) {
                    k = 0;
                    while(mx_strcmp(arrarr[j + 1], set[k]) != 0) k++;
                    matrix[i][k] = mx_atoi(arrarr[j + 2]);
                }
                else {
                    k = 0;
                    while(mx_strcmp(arrarr[j - 1], set[k]) != 0) k++;
                    matrix[i][k] = mx_atoi(arrarr[j + 1]);
                }
            }
            j++;
        }
        i++;
    }
    return matrix;
}
