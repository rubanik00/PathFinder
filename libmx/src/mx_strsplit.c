#include "libmx.h"

static int mx_wordlen(const char *s, char c) {
    int i = 0;
    char *temp = (char *)s;

    while(*temp++ != c) 
        i++;
    return i;
}

char **mx_strsplit(const char *s, char c) {
    size_t count = mx_count_words(s, c);
    char **res = (char **)malloc((count + 1) * sizeof(char *));
    int wl = 0;
    int i = 0;

    if (!s) 
        return NULL;
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
} // 20
