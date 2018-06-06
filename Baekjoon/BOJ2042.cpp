#include <stdio.h>

int N, M, K;
long long a[1000010];
long long tree[1000010];
void update(int i, int diff);
long long sum(int i);

int main(void) {
	scanf("%d %d %d", &N, &M, &K);
	register int i;
	for (i = 1; i <= N; i++) {
		scanf("%lld", a + i);
		update(i, a[i]);
	}
	for (i = 0; i < M + K; i++) {
		int mode, b;
		long long c;
		scanf("%d %d %lld", &mode, &b, &c);
		if (mode == 1) {
			update(b, c - a[b]);
			a[b] = c;
		}
		else printf("%lld\n", sum(c) - sum(b - 1));
	}

	return 0;
}

void update(int i, int diff) {
	while (i <= N) {
		tree[i] += diff;
		i += (i & -i);
	}
}

long long sum(int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}