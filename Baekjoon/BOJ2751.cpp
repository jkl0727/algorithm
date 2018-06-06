#include <stdio.h>

int end = 1;
int N;
int queue[1000010];

void swap(int &a, int &b) {
	int temp = a;
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

int dequeue(void) {
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

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int temp;
		scanf("%d", &temp);
		enqueue(temp);
	}

	for (int i = 0; i < N; ++i) {
		printf("%d\n", dequeue());
	}

	
	return 0;
}