#include "pathfinder.h"

static void check_index (t_island *temp, t_island *previous) {

    if(temp->next)
        previous->next = temp->next;
    else 
        previous->next = NULL;
        free(temp);
        temp = NULL;
}

void mx_pop_index(t_island **unvisited, int index) {
    t_island *temp = NULL;
    t_island *previous = NULL;

    if (!unvisited || !(*unvisited)) 
        return;
    if ((*unvisited)->indexIslnd == index)
        mx_pop_front_island(&(*unvisited));
    else {
        temp = *unvisited;
        previous = temp;
        while (temp != NULL && temp->indexIslnd != index) {
            previous = temp;
            temp = temp->next;
        }
        if (temp && temp->indexIslnd == index)
            check_index(temp, previous);
    }
} // 18
