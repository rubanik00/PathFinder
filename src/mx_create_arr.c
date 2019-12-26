#include "pathfinder.h"

static void check_island12(char *island1, char *island2, char *dist, int nline) {
	char *index = NULL;

	if (mx_strcmp(island1,island2) == 0 && mx_atoi(dist) != 0) {
		nline++;
		index = mx_itoa(nline);
		mx_printerr("error: line ");
		mx_printerr(index);
		mx_printerr_exit(" isn't valid\n");
	}
}

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
} // 16

static void mx_fill_islands(char ***arrarr, char **lines) {
	char **arr = *arrarr;
	char *island1 = NULL;
	char *island2 = NULL;
	char *dist = NULL;
	int line = 1;

	while(lines[line]) {
		larr(lines[line], &island1, &island2, &dist);
		check_island12(island1, island2, dist, line);
		*arr = mx_strdup(island1);
		arr++;
		mx_strdel(&island1);
		*arr = mx_strdup(island2);
		arr++;
		mx_strdel(&island2);
		*arr = mx_strdup(dist);
		line++, arr++;
		mx_strdel(&dist);
	}
	*arr = NULL;
} // 18

void mx_create_arr(char **lines, char ***arrarr){
	int line = 1;

	while (lines[line])
		line++;
	*arrarr = (char **)malloc((line * 3 + 1) * sizeof(char *));
	mx_fill_islands(&(*arrarr), lines);
}
