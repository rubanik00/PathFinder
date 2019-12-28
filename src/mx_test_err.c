  #include "pathfinder.h"

static void mx_print_invalid(int nline) {
	nline++;
	char *index = mx_itoa(nline);
	mx_printerr("error: line ");
	mx_printerr(index);
	mx_printerr_exit(" isn't valid\n");
}

static void part_check(char **lines, int n, int copy_i, int i) {
	while (mx_isdigit(lines[n][copy_i]))
			copy_i++;
		if (copy_i - i == 0 || lines[n][copy_i] != '\0') 
			mx_print_invalid(n);
}

static void mx_checkline(char **lines, int nline) {
	int i = 0;
	int copy_i = 0;

	for (int n = 1; n <= nline; n++) {
		i = 0;
		copy_i = 0;
		while (mx_isalpha(lines[n][i])) 
			i++;
		if (i == 0 || lines[n][i] != '-')
			mx_print_invalid(n);
		i++;
		copy_i = i;
		while (mx_isalpha(lines[n][copy_i])) 
			copy_i++;
		if (copy_i - i == 0 || lines[n][copy_i] != ',')
			mx_print_invalid(n);
		copy_i++;
		i = copy_i;
		part_check(lines, n, copy_i, i);
	}
}

static void mx_parserr(char *file) {
	char **lines = mx_strsplit(file, '\n');
	int nline = 0, at = 0;
	
	while (lines[nline]) 
		nline++;
	if (lines[0][0] == '0')
		mx_printerr_exit("error: zero isn't allowed\n");
	while (lines[0][at]) {
		if (!mx_isdigit(lines[0][at]))
			mx_printerr_exit("error: line 1 isn't valid\n");
		at++;
	}
	mx_checkline(lines, nline-1);
	mx_check_spaces(lines, file);
	mx_del_strarr(&lines);
}

void mx_test_err(int argc, char *file, char **argv) {
	if (argc != 2)
		mx_printerr_exit("usage: ./pathfinder [filename]\n");
	if (!file) {
		 mx_printerr("error: file ");
		 mx_printerr(argv[1]);
		 mx_printerr_exit(" doesn't exist\n");
	}
	if (mx_strlen(file) == 0) {
		mx_printerr("error: file ");
		mx_printerr(argv[1]);
		mx_printerr_exit(" is empty\n");
	}
	mx_parserr(file);
}
