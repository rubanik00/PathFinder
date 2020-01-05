#include "pathfinder.h"

t_li *mx_create_l() {
	t_li *l = malloc(sizeof(t_li));

	l->un = NULL;
	l->v = NULL;
	l->cur = NULL;
	l->sh = NULL;
	return l;
}
