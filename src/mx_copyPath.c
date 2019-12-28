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
}

t_path *mx_copyPath(t_path **data) {
	t_path *cur = NULL;
	t_path *res = NULL;
	t_path *new = NULL;
	t_path *fast = NULL;

	if (*data)
		cur = *data;
	res = addOne(&cur);
	fast = res;
	cur = cur->nextPath;
	while (cur) {
		new = addOne(&cur);
		mx_addLink(&fast, &new);
		fast = fast->nextPath;
		cur = cur->nextPath;
	}
	return res;
}
