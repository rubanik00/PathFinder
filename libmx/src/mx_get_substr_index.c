#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {

	if (!str || !sub) {
		return -2;
	}
	char *ptr = mx_strstr(str,sub);
	if (!ptr){
		return -1;
	}
	return ptr - str;
}
