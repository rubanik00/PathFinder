#include "pathfinder.h"

void mx_push_back_island (t_island **island, int isl, int dist) {
    t_island *new = mx_create_island(isl, dist);
    t_island *last = *island;

    if (*island == NULL) {
	    *island = new;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new;
    return;
} // 12
