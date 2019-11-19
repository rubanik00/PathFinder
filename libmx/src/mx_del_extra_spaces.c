#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {

	char *trim = NULL;
	char *final_str = NULL;
	int final_len = 0;
	int j = 0;

	if (str == NULL)
		return NULL;

	trim = mx_strtrim(str);

	final_len = mx_strlen(trim);

	for (int i = 0; i < mx_strlen(trim) - 1; i++) {
		if (mx_isspace(trim[i]) && mx_isspace(trim [i + 1])) {
			final_len--;
		}
	}

	final_str = mx_strnew(final_len);

	for (int i = 0; i < mx_strlen(trim); i++) {
		if (mx_isspace(trim[i]) && mx_isspace(trim [i + 1])) {
			continue;
		}
		else {
			final_str[j] = trim[i];
		}
		j++;
	}
	mx_strdel(&trim);
	return final_str;
}
