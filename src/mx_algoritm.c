#include "pathfinder.h"

static void displayPath(t_path **disp, char **set) {
	t_path *bond = *disp;

	while(bond) {
		while(bond->nextConnect){
			printf("%s  %d\n", set[bond->idPath], bond->distPath);
			bond = bond->nextConnect;
		}
		printf("%s  %d\n\n", set[bond->idPath], bond->distPath);
		bond = bond->nextPath;
	}
	printf("%s\n", "next");
} // 10

static void algoritm (int **matrix, char **set, int size, int root) {
    t_island *unvisited = NULL;
    t_island *visited = NULL;
    t_island *head = NULL;
    t_island *current = NULL;
    t_island *shortest = NULL;
    t_path *first = mx_create_path(root, 0);
    int isl1 = 0;
    int isl2 = 0;
    int mat = 0;

    for (int i = 0; i < size; i++)
        mx_push_back_island(&unvisited, NULL, i, 0); // заполнем лист нулями
    current = unvisited;
    while (current->indexIslnd != root) 
        current = current->next;
        mx_push_back_island(&visited, &first, current->indexIslnd, current->distTo);
        mx_pop_index(&unvisited, root);
    current = visited;

    while (unvisited) {
        head = unvisited;
        while (head != NULL) {
            isl1 = current->indexIslnd;
            isl2 = head->indexIslnd;
            mat = matrix[isl1][isl2];

            if (mat != 0 && head->distTo == 0) { // если запись дистанции уже есть
                head->distTo = current->distTo + mat;
                head->path = mx_addPath(&current->path, isl2, mat);
            }
            else if (mat != 0) {
                if (current->distTo + mat == head->distTo)
					mx_push_back_path(&head->path, &current->path, isl2, mat);
                if (current->distTo + mat < head->distTo) { // если запись дистанции длинее чем новый путь
                    head->distTo = current->distTo + mat; // меняем на новый путь
                    mx_dellPath(&head->path);
                    head->path = mx_addPath(&current->path, isl2, mat);
                }
            }
            head = head->next;
        }
        shortest = mx_short_dist(&unvisited);
        mx_printint(shortest->indexIslnd);
        mx_push_back_island(&visited, &shortest->path, shortest->indexIslnd, shortest->distTo);
        mx_pop_index(&unvisited, shortest->indexIslnd);
        current = current->next;
    }
    mx_printchar('\n');

    for(int j = 0; j < size; j++) {
		current = visited;
		while (current->indexIslnd != j)
			current = current->next;
		displayPath(&current->path, set);
	}

    while (visited != NULL) {
        //printf("%s %d \n", set[visited->indexIslnd], visited->distTo);
        mx_dellPath(&visited->path);
        mx_pop_front_island(&visited);
    }
 } // 60

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
} // 9
