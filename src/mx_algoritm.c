#include "pathfinder.h"

static t_island *create_island (int isl, int dist) {
    t_island *node = (t_island *) malloc(sizeof(t_island));

    node->indexIslnd = isl;
    node->distTo = dist;
    node->next = NULL; 
    return node;
} // 7

static void push_back_island (t_island **island, int isl, int dist) {
    t_island *new = create_island(isl, dist);
    t_island *last = *island;

    if (*island == NULL) {
	    *island = new;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new;
    return;
} // 12

static void pop_front (t_island **head) {
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
} // 14

static void pop_index (t_island **unvisited, int index) {
    t_island *temp = NULL;
    t_island *previous = NULL;
    if (!unvisited || !(*unvisited)) 
        return;
    if ((*unvisited)->indexIslnd == index)
        pop_front(&(*unvisited));
    else {
        temp = *unvisited;
        previous = temp;
        while (temp != NULL && temp->indexIslnd != index) {
            previous = temp;
            temp = temp->next;
        }
        if (temp && temp->indexIslnd == index) {
            if(temp->next)
                previous->next = temp->next;
            else 
                previous->next = NULL;
            free(temp);
            temp = NULL;
        }
    }
}

static void algoritm (int **matrix, char **set, int size, int root) {
    t_island *unvisited = NULL;
    t_island *visited = NULL;
    t_island *head = NULL;
    t_island *current = NULL;
    t_island *shortest = NULL;

    for (int i = 0; i < size; i++)
        push_back_island(&unvisited, i, 0); // заполнем лист нулями

        current = unvisited;

    while (current->indexIslnd != root) 
        current = current->next;
    
        push_back_island(&visited, current->indexIslnd, current->distTo);
        pop_index (&unvisited, root);
    
    current = visited;
    
    while (unvisited) {
        head = unvisited;
        while (head != NULL) {
            int isl1 = current->indexIslnd;
            int isl2 = head->indexIslnd;

            if (matrix[isl1][isl2] != 0 && head->distTo == 0)  // если запись дистанции уже есть
                head->distTo = current->distTo + matrix[isl1][isl2];
            else if (matrix[isl1][isl2] != 0)
                if(current->distTo + matrix[isl1][isl2] < head->distTo) // если запись дистанции длинее чем новый путь
                    head->distTo = current->distTo + matrix[isl1][isl2]; // меняем на новый путь
            head = head->next;
        }
        shortest = mx_short_dist(&unvisited);
        push_back_island(&visited, shortest->indexIslnd, shortest->distTo);
        pop_index (&unvisited, shortest->indexIslnd);
        current = current->next;

    }
    while (visited != NULL) {
        printf("%s %d \n", set[visited->indexIslnd], visited->distTo);
        pop_front(&visited);
    }
 } // 35

void mx_main_algoritm (int **matrix, char **set) {
    int size = 0;
    int i = 0;

    while (set[size]) size++;
    
    while (i < size) {
        algoritm (matrix, set, size, i);
        i++;
        mx_printchar('\n');
    }
} // 10
