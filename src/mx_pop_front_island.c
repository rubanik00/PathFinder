#include "pathfinder.h"

void mx_pop_front_island(t_island **head) {
    if (!head || !(*head)) 
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    else {
        t_island *p = (*head)->next;
        free(*head);
        *head = p;
    }
}
