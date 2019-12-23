#include "libmx.h"

char *mx_strnew(const int size) {
	char *str = NULL;
	int i = 0;

	if (size < 0) 
		return NULL;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL) 
		return NULL;
	for (; i < size; i++) 
		str[i] = '\0';
	str[i] = '\0';
	return str;
}
