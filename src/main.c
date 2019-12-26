#include "pathfinder.h"

int main (int argc, char *argv[]) {
    mx_test_err(argc, argv);
    mx_parse(argv[1]);
    system("leaks a.out");
    return 0;
}
