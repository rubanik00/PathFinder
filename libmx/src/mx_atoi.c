#include "libmx.h"

int mx_atoi(const char *str) {
	int result = 0;
	int i = -1;
	int sign = 1;

	while (str[++i]) {
		if (!mx_isspace(str[i])) {
			if (str[i] == '-') {
				sign = - 1;
				break;
			}
			else if (str[i] == '+') {
				break;
			}
			i--;
			break;
		}
	}
	while(str[++i]) {
		if (mx_isdigit(str[i])) {
			result = result * 10 + str[i] - '0';
		}
		if (!mx_isdigit(str[i])) {
			return result * sign;
		}
	}
	return result * sign;
}
