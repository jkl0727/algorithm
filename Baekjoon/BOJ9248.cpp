#include <stdio.h>

#define MAX_LEN 500010
char s[MAX_LEN];
int SA[MAX_LEN], g[MAX_LEN], tg[MAX_LEN], tmp[MAX_LEN], r[MAX_LEN];
int LCP[MAX_LEN];
int t = 1;

int cmp(int x, int y) {
	if (g[x] == g[y])
		return g[x + t] < g[y + t];
	return g[x] < g[y];
}

int strlen(char *str) {
	register int i = 0;
	while (str[i] != NULL) {
		i++;
	}
	return i;
}


void merge_sort(int s, int e) {
	if (s >= e) return;

	int m = (s + e) / 2;
	merge_sort(s, m);
	merge_sort(m + 1, e);

	int id1 = s;
	int id2 = m + 1;
	int idx = s;

	while (id1 <= m || id2 <= e) {
		if (id2 > e || (id1 <= m && cmp(SA[id1], SA[id2]))) {
			tmp[idx++] = SA[id1++];
		}
		else tmp[idx++] = SA[id2++];
	}

	register int i;
	for (i = s; i <= e; ++i) {
		SA[i] = tmp[i];
	}
}

void get_suffix(void) {
	int n = strlen(s);
	register int i;
	for (i = 0; i < n; ++i) {
		g[i] = (int)s[i] - 'a';
		SA[i] = i;
	}

	while (t <= n) {
		g[n] = -1;
		merge_sort(0, n - 1);
		tg[SA[0]] = 0;

		for (i = 1; i < n; i++) {
			if (cmp(SA[i-1], SA[i]) ){
				tg[SA[i]] = tg[SA[i - 1]] + 1;
			}
			else tg[SA[i]] = tg[SA[i - 1]];
		}
		
		for (i = 0; i < n; i++) g[i] = tg[i];
		
		t <<= 1;
	}

	for (i = 0; i < n; i++) {
		r[SA[i]] = i;
	}
	int len = 0;
	for (i = 0; i < n; i++) {
		int k = r[i];
		if (k) {
			int j = SA[k - 1];
			while (s[i + len] == s[j + len]) len++;
			LCP[k] = len;
			if (len) --len;
		}
	}
}

int main(void) {
	scanf("%s", s);
	get_suffix();
	int n = strlen(s);
	for (int i = 0; i < n; ++i) {
		printf("%d ", SA[i] + 1);
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		if(!i) printf("x ");
		else printf("%d ", LCP[i]);
	}
	return 0;
}