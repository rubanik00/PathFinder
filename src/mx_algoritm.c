#include "pathfinder.h"

static void main_algo(int **matrix, char **set, int root, int size) {
	t_island *unvisited = NULL; // лист непройденных нод
	t_island *visited = NULL; // лист пройденных нод
	t_island *current = NULL;
	t_island *shortest = NULL;

	for(int i = 0; i < size; i++) {
		mx_printstr(set[i]);
		mx_printstr(" -- ");
		mx_printint(i);
		mx_printchar('\n');
	}

	for (int i = 0; i < size; i++)
		mx_push_back_island(&unvisited, NULL, i, 0);  // заполнение пустыми нодами
	current = unvisited;
	while(current->indexIslnd != root)
		current = current->next;
	current->path = mx_create_path(root, 0);
	mx_push_back_island(&visited, &current->path, current->indexIslnd, current->distTo);
	mx_pop_middle_island(&unvisited, root);
	current = visited;

	while (unvisited) {
		t_island *head = unvisited;
		while (head != NULL) {
			int isl1 = current->indexIslnd;
			int isl2 = head->indexIslnd;
			int mat = matrix[isl1][isl2];

			if (mat != 0 && head->distTo == 0) { // запись еще неизвестной дист 
				head->distTo = current->distTo + mat;
				head->path = mx_addPath(&current->path, isl2, mat);
			} else if (mat != 0) {// перезапись дист
				if (current->distTo + mat == head->distTo)
					mx_push_backPath(&head->path, &current->path, isl2, mat);
				if (current->distTo + mat < head->distTo) {
					head->distTo = current->distTo + mat;
					mx_delPath(&head->path);
					head->path = mx_addPath(&current->path, isl2, mat);
				}
			}
			head = head->next;
		}
		shortest = mx_short_dist(&unvisited);
		mx_push_back_island(&visited, &shortest->path, shortest->indexIslnd, shortest->distTo);
		mx_pop_middle_island(&unvisited, shortest->indexIslnd);
		current = current->next;
		if (current->path == NULL) {
			// mx_delMat(&matrix, set);
			mx_printerr_exit("error: combination of two islands has not a path between them\n");
		}
	}
	// mx_printOutput(&visited, root+1, size, set);
	while (visited != NULL)
	{
		mx_delPath(&visited->path);
		mx_pop_front_island(&visited);
	}
} // 57

void mx_algoritm(int **matrix, char **set) {
	int size = 0;

	int i = 0;
	while (set[size]) size++;

	 while (i < size - 1) {
		main_algo(matrix, set, i, size);
		i++;
	 }
}
