  #include "pathfinder.h"

static void mx_print_invalid(int n) {
    char *index = NULL;
    n++;
    index = mx_itoa(n);
    mx_printerr("error: line ");
    mx_printerr(index);
    mx_printerr(" isn't valid\n");
    exit(EXIT_FAILURE);
}

static void mx_checklines(char **src, int n) {
    while (n > 0) {
        int i = 0, cp_i = 0;
        while (mx_isalpha(src[n][i])) i++;
        if (i == 0 || src[n][i] != '-')
            mx_print_invalid(n);
        i++, cp_i = i;
        while(mx_isalpha(src[n][cp_i])) cp_i++;
        if (cp_i - i == 0 || src[n][cp_i] != ',')
            mx_print_invalid(n);
        cp_i++, i = cp_i;
        while(mx_isdigit(src[n][cp_i])) cp_i++;
        if (cp_i - i == 0 || src[n][cp_i] != '\0')
            mx_print_invalid(n);
        n--;       
    }
}

static void mx_parserr(char *s) {
    char **src = mx_strsplit(s, '\n');
    int n = 0;
    int at = 0;

    while(src[n]) n++;
    while(src[0][at]) {
        if (!mx_isdigit(src[0][at])) {
            mx_printerr("error: line 1 isn't valid\n");
            exit(EXIT_FAILURE);
        }
        at++;
    }
    at = mx_atoi(src[0]);
    n -= 1;
    mx_checklines(src, n);
    mx_del_strarr(&src);
}

void mx_test_err(int argc, char *src[]) {
    char *file_str = NULL;

    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(EXIT_FAILURE);
    }
    file_str = mx_file_to_str(src[1]);
    if (!file_str) {
        mx_printerr("error:  file ");
        mx_printerr(src[1]);
        mx_printerr(" doesn't exist\n");
        exit(EXIT_FAILURE);
    }
    if (mx_strlen(file_str) == 0) {
        mx_printerr("error:  file ");
        mx_printerr(src[1]);
        mx_printerr(" is empty\n");
        exit(EXIT_FAILURE);   
    }
    mx_parserr(file_str);
    mx_strdel(&file_str);
} //22
