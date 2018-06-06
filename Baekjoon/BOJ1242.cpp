#include <iostream>
using namespace std;

int N, M, K;

int main(void) {
	scanf("%d %d %d", &N, &M, &K);
	register int i;
	for (i = 1; i <= N; i++) {
		int now_kill = M % (N - i + 1) == 0 ? (N - i + 1) : M % (N - i + 1);
		if (K == now_kill || i == N) break;
		K = K > now_kill ? K - now_kill : N - i + 1 - now_kill + K; 
	}
	printf("%d\n", i);

	return 0;
}