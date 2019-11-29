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

static void algoritm (int **matrix, char **set, int size, int root) {
    t_island *unvisited = NULL; // создаем лист
    t_island *head = NULL;
    t_island *current = NULL;
    int i = 0;

    for (i = root; i < size; i++) {
        push_back_island(&unvisited, i, 0); // заполнем лист нулями
    }
    for (int isl1 = root; isl1 < size; isl1++) {
        head = unvisited; // y
        current = unvisited; // x

        while(current->indexIslnd != isl1)
            current = current->next; // ищем опорный элемент х
        while(head->indexIslnd != isl1 + 1 && isl1 + 1 < size)
            head = head->next; // ищем опорный элемент y
        for (int isl2 = isl1 + 1; head && isl2 < size; isl2++) {
            if (matrix[isl1][isl2] != 0 && head->distTo) { // если запись дистанции уже есть
                if(current->distTo + matrix[isl1][isl2] < head->distTo) // если запись дистанции длинее чем новый путь
                    head->distTo = current->distTo + matrix[isl1][isl2]; // меняем на новый путь
            }
            else if (matrix[isl1][isl2] != 0 && !head->distTo) { // если дистанция 0
                head->distTo = current->distTo + matrix[isl1][isl2]; // записываем новую дистанцию
            }
            head = head->next;
        }
        current = current->next;
    }

    while (unvisited != NULL) {
        printf("%s %d \n", set[unvisited->indexIslnd], unvisited->distTo);

        pop_front(&unvisited);
    }
} // 35

void mx_main_algoritm (int **matrix, char **set) {
    int size = 0;
    int i = 0;

    while (set[size]) size++;
    
    // while (i < size) {
        algoritm (matrix, set, size, i);
    //     i++;
    // }
} // 10
