#include "pathfinder.h"

static void pop_allConnect(t_path **head) {
    t_path *next_conect = NULL;

    if (!head || !(*head))
        return;
    while((*head)->nextConnect) {
        next_conect = (*head)->nextConnect;
        free(*head);
        *head = next_conect;
    }
    if (!(*head)->nextConnect && !(*head)->nextPath) {
        free(*head);
        *head = NULL;
        return;
    }
} // 13

static void pop_nextPath(t_path **head) {
    t_path *next_conect = NULL;
    
    if (!head || !(*head))
        return;
    if ((*head)->nextPath == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    else {
        next_conect = (*head)->nextPath;
        free(*head);
        *head = next_conect;
    }   
} // 13

void mx_dellPath(t_path **head) {
    if (!head || !(*head))
        return;
    while (*head) {
        pop_allConnect(&(*head));
        pop_nextPath(&(*head));
    }
} // 5
