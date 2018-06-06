#include <stdio.h>

#define MAX(X, Y) (X) > (Y) ? (X) : (Y)
#define MIN(X, Y) (X) > (Y) ? (Y) : (X)

struct node {
	long long _min, _max;
};

int N, M, cnt;
long long arr[100010];
node tree[1<<18];
node a[1<<18];
node b[1<<18];
node tree_init(int l, int r, int n);
void find(int n, int l, int r, int start, int end, node &ret);

int main(void) {
	scanf("%d %d", &N, &M);
	register int i;
	for (i = 1; i<=N; i++) {
		scanf("%lld", arr+i);
	}
	tree_init(1, N, 1);
	for (i = 0; i < M; i++) {
		node ret;
		ret._min = 1000000000;
		ret._max = 1;
		int l, r;
		scanf("%d %d", &l, &r);
		find(1, l, r, 1, N, ret);
		printf("%lld %lld\n", ret._min, ret._max);
	}
	return 0;
}

node tree_init(int l, int r, int n) {
	int m = (l+r)/2;
	if (l==r) {
		tree[n]._max = arr[l];
		tree[n]._min = arr[l];
		return tree[n];
	}
	else {
		int temp = cnt++;
		a[temp] = tree_init(l, m, 2*n);
		b[temp] = tree_init(m+1, r, 2*n+1);
		tree[n]._min = MIN(a[temp]._min, b[temp]._min);
		tree[n]._max = MAX(a[temp]._max, b[temp]._max);
		return tree[n];
	}
}

void find(int n, int l, int r, int start, int end, node &ret) {
	if (l > end||r < start) {
		return;
	}
	if (l<=start && r>=end) {
		ret._min = MIN(ret._min, tree[n]._min);
		ret._max = MAX(ret._max, tree[n]._max);
		return;
	}
	find(2*n, l, r, start, (start+end)/2, ret);
	find(2*n+1, l, r, (start+end)/2+1, end, ret);
}