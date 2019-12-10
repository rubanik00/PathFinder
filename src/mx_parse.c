#include "pathfinder.h"

static int mx_count_island(char **arr, char *numOfIsland) {
    int count = 0;

    if (arr[0]) count++;
    for (int i = 1; arr[i] != NULL; i++) {
        if (mx_isdigit(arr[i][0])) i++;
        if (arr[i] == 0) break;
        for (int j = i - 1; j >= 0; j--) {
            if (mx_strcmp(arr[i], arr[j]) == 0) break;
            if (j == 0) count++;
        }
    }
    if (count != mx_atoi(numOfIsland)) {
       mx_printerr("error: invalid number of islands\n");
    }
    return count;
} //21

static void mx_create_set(char ***set, char ***arrarr, char *numOfIsland) {
    char **arr = *arrarr;
    int i = 0;
    int j = 0;
    int flag = 0;
    int count = mx_count_island(arr, numOfIsland);
    *set = (char **)malloc((count + 2) * sizeof(char *));
    char **set1 = *set;

    while (*arr) {
        if (mx_isdigit(**arr)) arr++;
        j = 0, flag = 0;
        if (*arr) {
            while (set1[j]) {
                if (mx_strcmp(*arr, set1[j]) == 0) {   
                    arr++,flag++;
                    break;
                }
            j++;
            if (flag !=0) {
                arr++;
                continue;
            }
            }
            if (flag == 0) {
                set1[i] = mx_strdup(*arr);
                i++;
            }
        }
    }
    set1[i] = NULL;
} //24

static void mx_linearr(char *src, char **island1, char **island2, char **distance) {
    int slot = 0;
    char *src_cp = src;

    while (src_cp[slot] != '-') slot++;
    *island1 = mx_strndup(src_cp, slot);
    src_cp += slot + 1;
    slot = 0;
            
    while (src_cp[slot] != ',') slot++;
    *island2 = mx_strndup(src_cp, slot);
    src_cp += slot + 1;
    slot = 0;

    while (src_cp[slot] != '\0') slot++;
    *distance = mx_strndup(src_cp, slot);
    slot = 0;
} // 17

static void mx_create_arr(char **src, char ***arrarr) {
    char *island1 = NULL;
    char *island2 = NULL;
    char *distance = NULL;
    char **arr = NULL;
    int line = 1;

    while (src[line]) line++;
    *arrarr = (char **)malloc((line * 3 + 1) * sizeof(char *));
    arr = *arrarr;
    line = 1;

    while (src[line]) {
        mx_linearr(src[line], &island1, &island2, &distance);
        *arr = mx_strdup(island1);
        arr++;
        *arr = mx_strdup(island2);
        arr++;
        *arr = mx_strdup(distance);
        arr++, line++;
    }
    mx_strdel(&island1);
    mx_strdel(&island2);
    mx_strdel(&distance);
} //24

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
    matrix = mx_matrix(arrarr, set);
    // mx_print_strarr(set, "\n"); // Print Set
    //mx_print_matrix(matrix, set); //Priint Mat
    mx_main_algoritm(matrix, set); // Print Algoritm
    mx_strdel(&fd);
} // 24
