#include "pathfinder.h"

void mx_push_back_island(t_island **island, t_path **path, int isl, int dist) {
    t_island *new = mx_create_island(isl, dist);
    t_island *last = *island;

    if (path && *path) {
		new->path = mx_copyPath(&(*path));
	}
    else if (path && *path == NULL) {
        mx_printerr("error: combination of two "); 
        mx_printerr_exit("islands has not a path between them\n");
    }
    if (*island == NULL) {
	    *island = new;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new;
    return;
} // 15
