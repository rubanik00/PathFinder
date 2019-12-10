#include "pathfinder.h"

static void print_space(int n) {
    n++;
    char *index = mx_itoa(n);
    mx_printerr("error: line ");
    mx_printerr(index);
    mx_printerr_exit(" isn't valid\n");
}

void mx_check_spaces(char **src, char *file) {

    char *fl = file;
    char **sr = src;
    int i = 0;
    int len = 0;
    // mx_print_strarr(&fl, "\n");

    if (mx_isspace(fl[0]))
            mx_printerr_exit("error: line 1 isn't valid\n");
    while (*fl) {
        if (mx_isspace(*fl) && mx_isspace(*(fl + 1))) {
            while(sr[i]) {
                len = mx_strlen(sr[i]);
                if (mx_strncmp(fl - len, sr[i], mx_strlen(sr[i])) == 0) {
                    print_space(i+1);
                }
                i++;
            }
        }
        fl++;
    }
}