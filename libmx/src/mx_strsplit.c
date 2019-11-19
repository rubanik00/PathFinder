#include "libmx.h"

static int mx_wordlen(const char *s, char c) {

    int i = 0;
    char *temp = (char *)s;

    while(*temp++ != c)
        i++;
    return i;
}

char **mx_strsplit(const char *s, char c) {

    if (!s) return NULL;

    char *tmp = (char *)s;
    char **res = NULL;
    size_t count = 0;
    int wl = 0;
    int i = 0;

    count = mx_count_words(tmp, c);
    res = (char **)malloc((count + 1) * sizeof(char *));
    while(*s && *s != '\0') {
        if (*s != c) {
            wl = mx_wordlen(s, c);
            res[i] = mx_strnew(mx_wordlen(s, c));
            mx_strncpy(res[i], s, wl);
            i++;
            s += wl;
        }
        s++;
    }
    res[i] = NULL;
    return res;
}
