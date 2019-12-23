#include "libmx.h"

static char *frst_if_itoa(int number) {
    char *res = NULL;

    if (number == 0) {
        res = mx_strnew(1);
        mx_strcpy(res, "0");
        return res;
    }
    if (number == -2147483648) {
        res = mx_strnew(11);
        mx_strcpy(res, "-2147483648");
        return res;
    }
    return res;
}

static void main_func(int number, int flag, char *res, int counter) {
    int i = 0;

    while (number) {
        if (number < 10 && flag > 0) 
            res[i + 1] = '-';
        counter = number % 10;
        res[i] = counter + '0';
        number /= 10;
        i++;
    }
}
char *mx_itoa(int number) {
    char *res = NULL;
    int counter = 0;
    int n = number;
    int flag = 0;

    res = frst_if_itoa(number);
    while (n) {
        n /= 10;
        counter++;
    }
    if (number < 0) {
        flag = 1;
        number *= -1;
        counter++;
    }
    res = mx_strnew(counter);
    main_func(number, flag, res, counter);
    mx_str_reverse(res);
    return res;
} // 20
