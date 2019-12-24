#include "pathfinder.h"

static int count_flag(char **set1, char *arr) {
    int j = 0;
    int flag = 0;
    
    while (set1[j]) {
        if (mx_strcmp(arr, set1[j]) == 0) {   
            flag++;
            break;
        }
        j++;
    }
    return flag;
} // 10

static int set_dup(char **set1, char **arr, int i) {
    set1[i] = mx_strdup(*arr);
    set1[i+1] = NULL;
    i += 1;
    return i;
} // 4

void mx_create_set(char ***set, char ***arrarr, char *numOfIsland) {
    int count = mx_count_island(*arrarr, numOfIsland);
    *set = (char **)malloc((count + 1) * sizeof(char *));
    **set = NULL;
    char **arr = *arrarr;
    char **set1 = *set;
    int j = 0;
    int flag = 0;
    int i = 0;

    while (*arr) {
        if (mx_isdigit(**arr)) 
            arr++;
        j = 0, flag = 0;
        if (*arr) {
            flag = count_flag(set1, *arr);
            if (flag !=0) 
                arr++;
            if (flag == 0) 
                i = set_dup(set1, arr, i);
        }
    }
} // 20
