#include "pathfinder.h"

void mx_addLink(t_path **cur, t_path **new) {
	t_path *current = *cur;

	while(current->nextConnect) {
		current->nextPath = *new;
		current = current->nextConnect;
	}
	current->nextPath = *new;
}
