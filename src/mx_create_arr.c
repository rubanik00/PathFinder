#include "pathfinder.h"

static void larr(char *src, char **island1, char **island2, char **distance) {
    int slot = 0;
    char *src_cp = src;

    while (src_cp[slot] != '-') 
        slot++;
    *island1 = mx_strndup(src_cp, slot);
    src_cp += slot + 1;
    slot = 0;
    while (src_cp[slot] != ',') 
        slot++;
    *island2 = mx_strndup(src_cp, slot);
    src_cp += slot + 1;
    slot = 0;
    while (src_cp[slot] != '\0') 
        slot++;
    *distance = mx_strndup(src_cp, slot);
    slot = 0;
} // 18

static void fill_arr(char **src, char **arr) {
char *island1 = NULL;
char *island2 = NULL;
char *distance = NULL;
int line = 1;

    while (src[line]) {
        larr(src[line], &island1, &island2, &distance);
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
} // 18

void mx_create_arr(char **src, char ***arrarr) {
    char **arr = NULL;
    int line = 1;

    while (src[line]) 
        line++;
    *arrarr = (char **)malloc((line * 3 + 1) * sizeof(char *));
    arr = *arrarr;
    fill_arr(src, arr);
    
} // 10
