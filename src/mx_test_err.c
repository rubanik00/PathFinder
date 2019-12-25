  #include "pathfinder.h"

static void mx_print_invalid(int n) {
    char *index = NULL;
    n++;
    index = mx_itoa(n);
    mx_printerr("error: line ");
    mx_printerr(index);
    mx_printerr_exit(" isn't valid\n");
} // 5

static void mx_checklines(char **src, int nline) {
    int i = 0; 
    int cp_i = 0;
    
    if(nline <= 0)
        mx_print_invalid(1);
    for (int n = 1; n <= nline; n++) {
		i = 0, cp_i = 0;
		while(mx_isalpha(src[n][i])) 
            i++;
		if (i == 0 || src[n][i] != '-')
			mx_print_invalid(n);
		i++, cp_i = i;
		while(mx_isalpha(src[n][cp_i])) 
            cp_i++;
		if (cp_i - i == 0 || src[n][cp_i] != ',')
			mx_print_invalid(n);
		cp_i++, i = cp_i;
		while(mx_isdigit(src[n][cp_i])) 
            cp_i++;
		if (cp_i - i == 0 || src[n][cp_i] != '\0') 
			mx_print_invalid(n);
	}
} // 19

static void mx_parserr(char *s) {
    char **src = mx_strsplit(s, '\n');
    int n = 0;
    int at = 0;

    while(src[n]) 
        n++;
    while(src[0][at]) {
        if (src[0][0] == '0' && !src[1])
            exit(0);
        if (src[0][0] == '0' && !src[0][1] && src[1])
            mx_printerr_exit("error: invalid number of islands\n");
        if (src[0][0] == '0')
            mx_printerr_exit("error: line 1 isn't valid\n");
        if (!mx_isdigit(src[0][at]))
            mx_printerr_exit("error: line 1 isn't valid\n");
        at++;
    }
    at = mx_atoi(src[0]);
    mx_checklines(src, n-1);
    mx_check_spaces(src, s);
    mx_del_strarr(&src);
} // 20

void mx_test_err(int argc, char *src[]) {
    char *file_str = NULL;

    if (argc != 2)
        mx_printerr_exit("usage: ./pathfinder [filename]\n");
    file_str = mx_file_to_str(src[1]);
    if (!file_str) {
        mx_printerr("error:  file ");
        mx_printerr(src[1]);
        mx_printerr_exit(" does not exist\n");
    }
    if (mx_strlen(file_str) == 0) {
        mx_printerr("error:  file ");
        mx_printerr(src[1]);
        mx_printerr_exit(" is empty\n"); 
    }
    mx_parserr(file_str);
    mx_strdel(&file_str);
} // 16
