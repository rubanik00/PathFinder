#include "pathfinder.h"

static void algoritm (int **matrix, char **set, int size, int root) {
    t_island *unvisited = NULL;
    t_island *visited = NULL;
    t_island *head = NULL;
    t_island *current = NULL;
    t_island *shortest = NULL;
    int isl1 = 0;
    int isl2 = 0;

    for (int i = 0; i < size; i++)
        mx_push_back_island(&unvisited, i, 0); // заполнем лист нулями
    current = unvisited;
    while (current->indexIslnd != root) 
        current = current->next;
        mx_push_back_island(&visited, current->indexIslnd, current->distTo);
        mx_pop_index (&unvisited, root);
    current = visited;
    while (unvisited) {
        head = unvisited;
        while (head != NULL) {
            isl1 = current->indexIslnd;
            isl2 = head->indexIslnd;
            if (matrix[isl1][isl2] != 0 && head->distTo == 0)  // если запись дистанции уже есть
                head->distTo = current->distTo + matrix[isl1][isl2];
            else if (matrix[isl1][isl2] != 0)
                if(current->distTo + matrix[isl1][isl2] < head->distTo) // если запись дистанции длинее чем новый путь
                    head->distTo = current->distTo + matrix[isl1][isl2]; // меняем на новый путь
            head = head->next;
        }
        shortest = mx_short_dist(&unvisited);
        mx_push_back_island(&visited, shortest->indexIslnd, shortest->distTo);
        mx_pop_index (&unvisited, shortest->indexIslnd);
        current = current->next;
    }
    while (visited != NULL) {
        printf("%s %d \n", set[visited->indexIslnd], visited->distTo);
        mx_pop_front_island(&visited);
    }
 } // 34

void mx_main_algoritm (int **matrix, char **set) {
    int size = 0;
    int i = 0;

    while (set[size]) 
        size++;
    while (i < size) {
        algoritm (matrix, set, size, i);
        i++;
        mx_printchar('\n');
    }
} // 10
