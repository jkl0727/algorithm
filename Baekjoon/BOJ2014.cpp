#include <stdio.h>

int end = 1;
int N, K;
long long prime[110];
long long queue[10001000];

void swap(long long &a, long long &b) {
	long long temp = a;
	a = b;
	b = temp;
}

void enqueue(unsigned int x) {
	int i = end;
	queue[end++] = x;

	while (i > 1) {
		if (queue[i / 2] > queue[i]) swap(queue[i / 2], queue[i]);
		else break;
		i /= 2;
	}
}

long long dequeue(void) {
	swap(queue[1], queue[--end]);

	int i = 1;

	while (2 * i < end) {
		int left = i * 2;
		int right = left + 1;
		int smallest_i = i;

		if (queue[i] > queue[left]) smallest_i = left;
		if (right < end && queue[smallest_i] > queue[right]) smallest_i = right;
		if (i != smallest_i) {
			swap(queue[smallest_i], queue[i]);
			i = smallest_i;
		}
		else
			break;
	}

	return queue[end];
}

int main(void) {

	scanf("%d %d", &K, &N);
	long long head;
	for (int i = 0; i < K; ++i) {
		scanf("%lld", &prime[i]);
		enqueue(prime[i]);
	}

	for (int i = 0; i < N - 1; ++i) {
		head = dequeue();

		for (int j = 0; j < K; ++j) {
			long long value = head * prime[j];
			if(value <= 2100000000)
				enqueue(value);
			if (head % prime[j] == 0) break;
		}
	}

	printf("%lld\n", dequeue());

	return 0;
}