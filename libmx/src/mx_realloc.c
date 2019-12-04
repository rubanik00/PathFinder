#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *result;
    size_t length;

    if (size == 0 && ptr) {
        free(ptr);
        return NULL;
    }
    if (size && !ptr) return malloc(size);
    length = mx_strlen(ptr);
    if (length > size) {
        result = malloc(length);
        if (!result) return NULL;
        result = mx_memmove(result, ptr, length);
    }
    else {
        result = malloc(size);
        if (!result) return NULL;
        result = mx_memmove(result, ptr, size);
    }
    return result;
} //21
