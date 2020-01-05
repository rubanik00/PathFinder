#include "pathfinder.h"

static void count_err(int count, char *nIslands) {
	if (count == 0 || count != mx_atoi(nIslands) || count == 1)
		mx_printerr_exit("error: invalid number of islands\n");
}

static int mx_count_set(char **arr, char *nIslands) {
	int count = 0;
	int j = 0;

	if (arr && *arr) {
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
	count_err(count, nIslands);
	return count;
} // 20

static int mx_flag(char *arr, char **set1) {
	int j = 0;
	int flag = 0;

	while(set1[j]) {
		if (mx_strcmp(arr, set1[j]) == 0) {
			flag++;
			break;
		}
		j++;
	}
	return flag;
}


static void mx_set(char ***set, char ***arrarr) {
	char **arr = *arrarr;
	char **set1 = *set;
	int i = 0;

	for (int flag = 0; *arr; flag = 0) {
		if (mx_isdigit(**arr))
			arr++;
		if (*arr) {
			flag = mx_flag(*arr, set1);
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
}

void mx_create_set(char ***set, char ***arrarr, char *nIslands) {
	int count = mx_count_set(*arrarr, nIslands);
	
	*set = (char **)malloc((count + 1) * sizeof(char *));
	**set = NULL;
	mx_set(&(*set), &(*arrarr));
}
