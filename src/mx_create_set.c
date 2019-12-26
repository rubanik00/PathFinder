#include "pathfinder.h"

static int count_island(char **arr, char *numOfIsland) {
    int count = 0;
	int j = 0;

	if(arr && *arr) {
		if (arr[0]) 
			count++;
		for (int i = 1; arr[i] != NULL; i++) {
			if (mx_isdigit(arr[i][0])) 
				i++;
			if (arr[i] == NULL) 
				break;
			for (j = i - 1; j >= 0; j--) {
				if (mx_strcmp(arr[i], arr[j]) == 0) 
					break;
				if (j == 0) 
					count++;
			}
		}
	}
	if (count == 0 || count != mx_atoi(numOfIsland) || count == 1) {
		mx_printerr_exit("error: invalid number of islands\n");
	}
	return count;
} // 20

static int count_flag(char **set1, char *arr) {
    int j = 0;
    int flag = 0;
    
    while (set1[j]) {
        if (mx_strcmp(arr, set1[j]) == 0) {   
            flag++;
            break;
        }
        j++;
    }
    return flag;
} // 10

static void set_algo(char ***set, char ***arrarr) {
    char **arr = *arrarr;
    char **set1 = *set;
    int i = 0;

    for (int flag = 0; *arr; flag = 0) {
		if (mx_isdigit(**arr))
			arr++;
		if (*arr) {
			flag = count_flag(set1, *arr);
			if (flag != 0) {
				arr++;
				continue;
			}
			if (flag == 0) {
				set1[i] = mx_strdup(*arr);
				set1[i+1] = NULL;
				i++;
			}
			arr++;
		}
	}
} // 20

void mx_create_set(char ***set, char ***arrarr, char *numOfIsland) {
    int count = count_island(*arrarr, numOfIsland);
    *set = (char **)malloc((count + 1) * sizeof(char *));
    **set = NULL;
    set_algo(&(*set), &(*arrarr));
} // 4
