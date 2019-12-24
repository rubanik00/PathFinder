#include "pathfinder.h"

static void compare(t_path **newOne, t_path **preOne, int *flag) {
	if (*newOne && *preOne) {
		if ((*newOne)->idPath != (*preOne)->idPath)
			*flag = 1;
		if ((*newOne)->distPath != (*preOne)->distPath)
			*flag = 1;
	}
	if (!(*newOne) || !(*preOne))
		*flag = 1;
} // 7

static void step(t_path **old, t_path **path, t_path **new) {
	*path = *new;
	*old = (*old)->nextPath;
}

int mx_uniquePath(t_path **new, t_path **pre) {
    int flag = -1;
	t_path *path = *new;
	t_path *old = *pre;

    while (old) {
        if (old->nextConnect != NULL || !path) {
            compare(&path, &old, &flag);
            step(&old, &path, &(*new));
            if (flag == -1)
                return -1;
            if (old)
                flag = -1;
            continue;
        }
        compare(&path, &old, &flag);
        path = path->nextConnect;
        old = old->nextConnect;
    }
    return flag;
} // 18
