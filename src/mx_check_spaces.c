#include "pathfinder.h"

static void mx_print_invalid(int nline) {
	char *index = NULL;

	nline++;
	index = mx_itoa(nline);
	mx_printerr("error: line ");
	mx_printerr(index);
	mx_printerr_exit(" is not valid\n");
}

void mx_check_spaces(char **lines, char *file) {
	char *fl = file;
	char **ln = lines;
	int i = 0;
	int len = 0;

	if (*fl == '\n')
		mx_print_invalid(0);
	while (*fl) {
		if (*fl == '\n' && *(fl + 1) == '\n')
			while (ln[i]) {
				len = mx_strlen(ln[i]);
				if (mx_strncmp(fl - len, ln[i], mx_strlen(ln[i])) == 0)
					mx_print_invalid(i + 1);
				i++;
			}
		fl++;
	}
}
