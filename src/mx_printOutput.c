#include "pathfinder.h"

static void printLine(t_char **prd) {
	char *string = mx_strdup("========================================");

	mx_printstr(string);
	mx_printchar('\n');
	mx_printstr((*prd)->p);
	mx_printstr((*prd)->r);
	mx_printstr((*prd)->d);
	mx_printstr(string);
	mx_printchar('\n');
	mx_strdel(&(*prd)->p);
	mx_strdel(&(*prd)->r);
	mx_strdel(&(*prd)->d);
	mx_strdel(&string);
	free(*prd);
	*prd = NULL;
}

static t_char *createprd(t_path *bond, char **set) {
	t_char *prd = malloc(1 * sizeof(t_char));
	int i = 0;

	prd->p = mx_strdup("Path: ");
	mx_join(&(*prd).p, set[bond->idPath]);
	prd->r = mx_strdup("Route: ");
	mx_join(&(*prd).r, set[bond->idPath]);
	prd->d = mx_strdup("Distance: ");
	for(; bond; bond = bond->nextConnect)
		i++;
	prd->s = i;

	return prd;
}
static void addNextBond(t_char **prd, t_path *bond, int distTo, char **set) {
	mx_join(&(*prd)->r, " -> ");
	mx_join(&(*prd)->r, set[bond->idPath]);
	if (mx_strlen((*prd)->d) != 10)
		mx_join(&(*prd)->d, " + ");
	mx_join(&(*prd)->d, mx_itoa(bond->distPath));

	if (bond->nextConnect == NULL) {
		mx_join(&(*prd)->p, " -> ");
		mx_join(&(*prd)->p, set[bond->idPath]);
		if ((*prd)->s != 2) {
			mx_join(&(*prd)->d, " = ");
			mx_join(&(*prd)->d, mx_itoa(distTo));
		}
		mx_join(&(*prd)->r, "\n");
		mx_join(&(*prd)->p, "\n");
		mx_join(&(*prd)->d, "\n");
	}
}

static void displayPath(t_path **disp, int distTo, char **set) {
	t_path *bond = *disp;
	t_char *prd = NULL;

	while(bond) {
		prd = createprd(bond, set);
		bond = bond->nextConnect;
		while(bond->nextConnect) {
			addNextBond(&prd, bond, distTo, set);
			bond = bond->nextConnect;
		}
		addNextBond(&prd, bond, distTo, set);
		printLine(&prd);
		bond = bond->nextPath;
	}
}



void mx_printOutput(t_island **visited, int root, int size, char **set) {
	t_island *current = NULL;

	for(; root < size; root++) {
		current = *visited;
		while (current->indexIslnd != root)
			current = current->next;
		// mx_sortPath(&current->path);
		displayPath(&current->path, current->distTo, set);
		exit(1);
	}
}
