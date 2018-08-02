#include <stdio.h>

#define MAX 50

class node {
public:
	int n_child;
	int child[MAX + 1];

	node() {
		n_child = 0;
	}
};
 
node tree[MAX + 1];
int root[MAX + 1] = { 0, };
int N, root_i, ret;

void init(void) {
	N = 0;
	ret = 0;
	root_i = 0;
}

int check_leaf(int idx) {
	if (tree[idx].n_child == 0) {
		ret++;
		return 0;
	}
	else if (tree[idx].n_child == -1)
		return 1;

	for (int i = 0; i < tree[idx].n_child; ++i) {
		if (check_leaf(tree[idx].child[i])) {
			if (tree[idx].n_child == 1)
				ret++;
		}
	}
	return 0;
}

int main(void) {

	init();

	scanf("%d", &N);
	
	for (int i = 0; i < N; ++i) {
		int in;
		
		scanf("%d", &in);

		if (in != -1) {
			tree[in].child[tree[in].n_child++] = i;
		}
		else {
			root[root_i++] = i;
		}
	}

	int delete_i;

	scanf("%d", &delete_i);

	tree[delete_i].n_child = -1;
	
	for (int i = 0; i < root_i; ++i) {
		check_leaf(root[i]);
	}

	printf("%d\n", ret);

	return 0;
}