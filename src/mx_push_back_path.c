#include "pathfinder.h"

void mx_push_backPath(t_path **path, t_path **previous, int isl, int dist) {
	t_path *last = *path;
	t_path *cur = *previous;
	t_path *new = NULL;
	
	while (last->nextPath != NULL)
		last = last->nextPath;
	while (cur) {
		new = mx_addOnePath(&cur, isl, dist);
		if (mx_uniquePath(&new, &(*path)) == 1) {
			mx_addLink(&last, &new);
			last = last->nextPath;
		}
		cur = cur->nextPath;
	}
}
