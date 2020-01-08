#include "libmx.h"

char *mx_strtrim(const char *str) {
	int len = mx_strlen(str);
	char *dst = NULL;
	
	if (!str) 
		return NULL;
	while (mx_isspace(str[len - 1]) && len > 0)
		len--;
	while (mx_isspace(*str) && len > 0) {
		str++;
		len--;	
	}
	dst = mx_strnew(len); 
	mx_strncpy(dst, str, len);
	return dst;
}
