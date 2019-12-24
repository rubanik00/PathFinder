#include "pathfinder.h"

t_path *mx_addPath(t_path **previous, int isl, int dist) {
    t_path *res = NULL;
    t_path *now = NULL;
    t_path *new = NULL;
    t_path *fast = NULL;

    if(*previous)
        now = *previous;
    res = mx_addOnePath(&now, isl, dist);
    fast = res;
    if (now)
        now = now->nextPath;
    while (now) {
        new = mx_addOnePath(&now, isl, dist);
        mx_addLink(&fast, &new);
        fast = fast->nextPath;
        now = now->nextPath;
    }
    return res;
} // 17
