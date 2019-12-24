#include "pathfinder.h"

void mx_pop_front_island(t_island **head) {
	t_island *p = NULL;
    
    if (!head || !(*head)) return;
	if ((*head)->next == NULL) {
		free(*head);
		*head = NULL;
		return;
	}
	else {
		p = (*head)->next;
		free(*head); 
		*head = p;
	}
} // 12
