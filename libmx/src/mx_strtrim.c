#include "libmx.h"

char *mx_strtrim(const char *str) {
	if (!str)
		return NULL;

	int len = mx_strlen(str);

	while (mx_isspace(str[len - 1]) && len > 0){
		len--;
	}
	while (mx_isspace(*str) && len > 0) {
		str++;
		len--;	
	}
	char *dst = mx_strnew(len); 
	mx_strncpy(dst, str, len);
	return dst;
	
}
