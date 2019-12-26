#include "pathfinder.h"

void mx_delMat(int ***matrix, char **set) {
	int **mat = *matrix;
	int i = 0;
    
	while(set[i])
		i++;

	while(i >= 0) {
		free(*mat);
		mat++;
		i--;
	}
	free(*matrix);
	*matrix = NULL;
}
