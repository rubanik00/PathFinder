#include "pathfinder.h"

static void firs_if(t_island *temp, t_island *leftOne, int index) {
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

void mx_pop_middle_island(t_island **unvisited, int index) {
	t_island *temp = NULL;
	t_island *leftOne = NULL;

	if (!unvisited || !(*unvisited)) 
		return;
	if ((*unvisited)->indexIslnd == index) {
		mx_delPath(&((*unvisited)->path));
		mx_pop_front_island(&(*unvisited));
	}
	else {
		temp = *unvisited;
		leftOne = temp;
		while (temp != NULL && temp->indexIslnd != index) {
			leftOne = temp;
			temp = temp->next;
		}
		firs_if(temp, leftOne, index);
	}
}
