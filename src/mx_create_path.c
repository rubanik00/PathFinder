#include "pathfinder.h"

t_path *mx_create_path(int isl, int dist) {
	t_path *node = (t_path *)malloc(1 * sizeof(t_path));

	node->idPath = isl;
	node->distPath = dist;
	node->nextConnect = NULL;
	node->nextPath = NULL;
	return node;
}
