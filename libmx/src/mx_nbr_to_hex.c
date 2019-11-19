#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	int tmp;
	char temp;
	int i = 0;
	int length = 0;
	char *result = mx_strnew(100);

	while (nbr != 0) {
		tmp = nbr % 16;
		if (tmp < 10) {
			result[i] = tmp + 48;
			i++;
		}
		else {
			result[i] = tmp + 55;
			i++;
		}
		nbr /= 16;
	}
	i = -1;
	while (result[++i]) {
		length++;
	}
	for (int j = 0, k = length - 1; j < length / 2; j++) {
		temp = result[j];
		result[j] = result[k];
		result[k] = temp;
	}
	return result;
}
