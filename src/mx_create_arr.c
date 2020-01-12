#include "pathfinder.h"

static void check_island12(char *island1, char *island2, char *dis, int nline) {
    char *index = NULL;

    if (mx_strcmp(island1,island2) == 0 && mx_atoi(dis) != 0) {
        nline++;
        index = mx_itoa(nline);
        mx_printerr("error: line ");
        mx_printerr(index);
        mx_printerr_exit(" isn't valid\n");
    }
}

static void linearr(char *line, char **island1, char **island2, char **dis) {
    int i = 0;
    char *str = line;
    
    while(str[i] != '-') 
        i++;
    *island1 = mx_strndup(str, i);
    str += i + 1;
    i = 0;
    while(str[i] != ',') 
        i++;
    *island2 = mx_strndup(str, i);
    str += i + 1;
    i = 0;
    while(str[i] != '\0') 
        i++;
    *dis = mx_strndup(str, i);
}

static void fill_islands(char ***arrarr, char **lines, int line) {
    char **arr = *arrarr;
    char *island1 = NULL;
    char *island2 = NULL;
    char *dist = NULL;

    while(lines[line]) {
        linearr(lines[line], &island1, &island2, &dist);
        check_island12(island1, island2, dist, line);
        *arr = mx_strdup(island1);
        arr++;
        mx_strdel(&island1);
        *arr = mx_strdup(island2);
        arr++;
        mx_strdel(&island2);
        *arr = mx_strdup(dist);
        line++;
        arr++;
        mx_strdel(&dist);
    }
    *arr = NULL;
}

void mx_create_arr(char **lines, char ***arrarr){
    int line = 1;

    while (lines[line])
        line++;
    *arrarr = (char **)malloc((line * 3 + 1) * sizeof(char *));
    fill_islands(&(*arrarr), lines, 1);
}
