#include "pathfinder.h"

void mx_push_back_path(t_path **path, t_path **previous,int isl, int dist) {
    t_path *new = NULL;
    t_path *last = *path;
    t_path *pre = *previous;

    if (last)
        while (last->nextPath != NULL)
            last = last->nextPath;
    while (pre) {
        new = mx_addOnePath(&pre, isl, dist);
        if (mx_uniquePath(&new, &(*path)) == 1) {
            mx_addLink(&last, &new);
            last = last->nextPath;
        }
        pre = pre->nextPath;
    }
} // 15
