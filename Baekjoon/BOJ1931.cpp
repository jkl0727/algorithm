#include <iostream>
using namespace std;

int N;
int st[100000 + 10];
int et[100000 + 10];
int sorts[100000 + 10];
int sorte[100000 + 10];
int solve(void);
void merge_sort(int s, int e);

int main(void) {
	scanf("%d", &N);
	register int i;
	for (i = 0; i < N; i++) {
		scanf("%d %d", st + i, et + i);
	}
	merge_sort(0, N - 1);
	printf("%d\n", solve());
	return 0;
}

void merge_sort(int s, int e) {
	if (s == e) return;
	int m = (s + e) / 2;
	merge_sort(s, m);
	merge_sort(m + 1, e);

	register int idx = s;
	register int id1 = s;
	register int id2 = m + 1;
	while (id1 < m + 1 || id2 < e + 1 ) {
		if (id2 == e+1 || ((id1 < m+1) && et[id1] < et[id2])) {
			sorts[idx] = st[id1];
			sorte[idx++] = et[id1++];
		}
		else if (et[id1] == et[id2]) {
			if (id1 < m + 1 && st[id1] < st[id2]) {
				sorts[idx] = st[id1];
				sorte[idx++] = et[id1++];
			}
			else {
				sorts[idx] = st[id2];
				sorte[idx++] = et[id2++];
			}
		}
		else {
			sorts[idx] = st[id2];
			sorte[idx++] = et[id2++];
		}
	}
	register int i;
	for (i = s; i <= e; i++) {
		st[i] = sorts[i];
		et[i] = sorte[i];
	}
}

int solve(void) {
	int time, ret = 1;
	register int i;
	time = et[0];
	for (i = 1; i < N; i++) {
		if (time <= st[i]) {
			ret++; time = et[i];
		}
	}
	return ret;
}