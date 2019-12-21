#include "pathfinder.h"

static t_path *addOne(t_path **previous) {
	t_path *new = NULL;
	t_path *last = *previous;
	t_path *res = NULL;

	res = mx_create_path(last->idPath, last->distPath);
	new = res;
	last = last->nextConnect;
	while (last) {
		new->nextConnect = mx_create_path(last->idPath, last->distPath);
		last = last->nextConnect;
		new = new->nextConnect;
	}
	return res;
} // 14

t_path *mx_copyPath(t_path **data) {
    t_path *now = NULL;
	t_path *res = NULL;
	t_path *new = NULL;
	t_path *fast = NULL;

    if (*data) {
        now = *data;
    }
    res = addOne(&now);
	fast = res;
	now = now->nextPath;
	while (now) {
		new = addOne(&now);
		mx_addLink(&fast, &new);
		fast = fast->nextPath;
		now = now->nextPath;
	}
	return res;
} // 19
