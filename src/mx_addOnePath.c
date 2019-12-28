#include "pathfinder.h"

t_path *mx_addOnePath(t_path **previous, int isl, int dist) {
	t_path *new = NULL;
	t_path *last = *previous;
	t_path *res = NULL;

	if (!last)
		return res = mx_create_path(isl, dist);
	res = mx_create_path(last->idPath, last->distPath);
	new = res;
	last = last->nextConnect;
	while (last) {
		new->nextConnect = mx_create_path(last->idPath, last->distPath);
		last = last->nextConnect;
		new = new->nextConnect;
	}
	new->nextConnect = mx_create_path(isl, dist);
	return res;
}
