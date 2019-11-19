#include "libmx.h"

void mx_str_reverse(char *s) {

	int size = mx_strlen(s) - 1;

	for (int i = 0; i < mx_strlen(s) / 2; i++, size--) {
		char tmp = s[i];
		s[i] = s[size];
		s[size] = tmp;
	}
}
