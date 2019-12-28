#include "pathfinder.h"

void mx_pop_middle_island(t_island **unvisited, int index) {
	if (!unvisited || !(*unvisited)) return;
	if ((*unvisited)->indexIslnd == index) {
		mx_delPath(&((*unvisited)->path));
		mx_pop_front_island(&(*unvisited));
	}
	else {
		t_island *temp = *unvisited;
		t_island *leftOne = temp;
		while (temp != NULL && temp->indexIslnd != index) {
			leftOne = temp;
			temp = temp->next;
		}
		if (temp && temp->indexIslnd == index) {
			if (temp->next)
				leftOne->next = temp->next;
			else
				leftOne->next = NULL;
			mx_delPath(&temp->path);
			free(temp);
			temp = NULL;
		}
	}
}
