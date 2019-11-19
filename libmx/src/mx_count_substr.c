#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {

	if (!str || !sub)
 		return -1;
	
	int len = mx_strlen(sub);
	int counter = 0;

	if (len == 0)
		return 0;

	for (str = mx_strstr(str, sub); str; str = mx_strstr(str + len, sub))
		counter++;
	return counter;
}
