#include <stdio.h>

#define FULL 1
#define EMPTY 0

typedef struct {
	int lake, pri;
}info;

int N, M, T, L, last;
int forecast[1000000 + 10];
int lake_state[1000000 + 10];
int pri[1000000 + 10];
int t[1000000 + 10];
int result[1000000 + 10];
info min_heap[1000000 + 10];
void swap(info *a, info *b);
int compare(info a, info b);
int empty(void);
info pop(void);
void push(info n);

int main(void) {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		register int i;
		for (i = 0; i < L; i++) result[i] = 0;
		L = 0; last = 0;
		for (i = 0; i < M; i++) scanf("%d", &forecast[i]);
		for (i = 1; i <= N; i++) {
			lake_state[i] = FULL;
			t[i] = M;
		}
		for (i = M - 1; i >= 0; i--) {
			pri[i] = t[forecast[i]];
			t[forecast[i]] = i;
		}
		for (i = 1; i <= N; i++) {
			if (t[i] != M) {
				info temp; temp.pri = t[i]; temp.lake = i;
				push(temp);
			}
		}
		for (i = 0; i < M; i++) {
			if (!forecast[i]) {
				if (!empty()) {
					info temp = pop();
					lake_state[temp.lake] = EMPTY;
					result[L++] = temp.lake;
				}
				else result[L++] = 0;
			}
			else {
				if (lake_state[forecast[i]] == FULL) break;
				lake_state[forecast[i]] = FULL;
				info temp; temp.lake = forecast[i]; temp.pri = pri[i];
				push(temp);
			}
		}
		if (i == M) {
			printf("YES\n");
			for (i = 0; i < L; i++) printf("%d ", result[i]);
			printf("\n");
		}
		else printf("NO\n");
	}
	return 0;
}


void push(info n) {
	min_heap[++last] = n;
	register int c = last, p = c / 2;
	while (p > 0) {
		if (compare(min_heap[c], min_heap[p])) 
			swap(&min_heap[c], &min_heap[p]);
		else break;
		c = p; p = c / 2;
	}
}

info pop(void) {
	swap(&min_heap[1], &min_heap[last--]);
	register int i = 1;
	while (2 * i <= last) {
		int min = i, l = 2 * i, r = l + 1;
		if (compare(min_heap[l], min_heap[min]))
			min = l;
		if (r <= last && compare(min_heap[r], min_heap[min]))
			min = r;
		if (min != i) swap(&min_heap[min], &min_heap[i]);
		else break;
		i = min;
	}
	return min_heap[last + 1];
}

void swap(info *a, info *b) {
	info temp = *a;
	*a = *b;
	*b = temp;
}

int compare(info a, info b) {
	if (a.pri < b.pri) return 1;
	return 0;
}

int empty() {
	if (!last) return 1;
	return 0;
}