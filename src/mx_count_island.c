#include "pathfinder.h"
#include "stdio.h"

int mx_count_island(char **arr, char *numOfIsland) {
    int count = 0;
	int j = 0;

	if (arr[0]) count++;
	for (int i = 1; arr[i] != NULL; i++) {
		if (mx_isdigit(arr[i][0])) i++;
		if (arr[i] == NULL) break;
		for (j = i - 1; j >= 0; j--) {
			if (mx_strcmp(arr[i], arr[j]) == 0) break;
			if (j == 0) count++;
		}
	}
	if (count != mx_atoi(numOfIsland)) {
		mx_printerr_exit("error: invalid number of islands\n");
	}
	return count;
} // 17
