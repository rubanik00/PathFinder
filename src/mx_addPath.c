#include "pathfinder.h"

t_path *mx_addPath(t_path **previous, int isl, int dist) {
	t_path *cur = NULL;
	t_path *res = NULL;
	t_path *new = NULL;
	t_path *fast = NULL;

	if (*previous)
		cur = *previous;
	res = mx_addOnePath(&cur, isl, dist);
	fast = res;
	if (cur)
		cur = cur->nextPath;
	while (cur) {
		new = mx_addOnePath(&cur, isl, dist);
		mx_addLink(&fast, &new);
		fast = fast->nextPath;
		cur = cur->nextPath;
	}
	return res;
} // 17
