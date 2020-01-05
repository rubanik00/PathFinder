#include "pathfinder.h"

static int cmp(t_path *bond, t_path *fast) {
	while (bond->nextConnect && fast->nextConnect) {
		if (bond->idPath > fast->idPath)
			return 1;
		if (bond->idPath < fast->idPath)
			return 0;
		bond = bond->nextConnect;
		fast = fast->nextConnect;
	}
	if (bond->nextConnect && !fast->nextConnect)
		return 1;
	return 0;
}

static void swpD(t_path **disp, t_path **bond, t_path **fast) {
	t_path *temp = (*fast)->nextPath;
	t_path *cur = *disp;

	while(cur->nextPath != *fast)
		cur = cur->nextPath;
	mx_addLink(&cur, &(*bond));
	cur = *disp;
	if (*disp == *bond)
		*disp = *fast;
	else {
		while(cur && cur->nextPath != *bond)
			cur = cur->nextPath;
		mx_addLink(&cur, &(*fast));
	}
	mx_addLink(&(*fast), &(*bond)->nextPath);
	mx_addLink(&(*bond), &temp);
}

static void swp(t_path **disp, t_path **bond, t_path **fast) {
	t_path *temp = (*fast)->nextPath;
	t_path *cur = *disp;

	if ((*bond)->nextPath == *fast) {
			mx_addLink(&(*fast), &(*bond));
			mx_addLink(&(*bond), &temp);
		if (*disp == *bond)
			*disp = *fast;
		else {
			while(cur && cur->nextPath != *bond)
				cur = cur->nextPath;
			mx_addLink(&cur, &(*fast));
		}
	}
	else 
        swpD(&(*disp), &(*bond), &(*fast));
}

void mx_sortPath(t_path **disp, int sizeP) {
	t_path *bond = *disp;
	t_path *fast = (*disp)->nextPath;

	for(int i = 0; i < sizeP; i++) {
		for (bond = *disp; bond->index != i; bond = bond->nextPath)
			fast = bond->nextPath;
		while(fast) {
			if (cmp(bond, fast) == 1) {
				swp(&(*disp), &bond, &fast);
				for (bond = *disp; bond->index != i; bond = bond->nextPath)
					fast = bond->nextPath;
			}
			else 
				fast = fast->nextPath;
		}
	}
}
