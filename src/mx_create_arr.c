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
} // 16

static void mx_fill_islands(char ***arrarr, char **lines) {
	char **arr = *arrarr;
	char *island1 = NULL;
	char *island2 = NULL;
	char *dist = NULL;
	int line = 1;

	while(lines[line]) {
		larr(lines[line], &island1, &island2, &dist);
		*arr = mx_strdup(island1);
		arr++;
		*arr = mx_strdup(island2);
		arr++;
		*arr = mx_strdup(dist);
		line++, arr++;
		mx_strdel(&island1);
		mx_strdel(&island2);
		mx_strdel(&dist);
	}
	*arr = NULL;
}

void mx_create_arr(char **lines, char ***arrarr){
	int line = 1;

	while (lines[line]){
		line++;
	}
	*arrarr = (char **)malloc((line * 3 + 1) * sizeof(char *));
	mx_fill_islands(&(*arrarr), lines);
}
