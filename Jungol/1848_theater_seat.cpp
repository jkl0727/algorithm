#include <iostream>
#pragma warning (disable:4996)
using namespace std;

int fibo(int n);

int main(void) {
	int N, M, result = 1;

	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	int *point = new int[N];
	for (int i = 0; i < M; ++i) cin >> point[i];

	for (int i = 0; i < M; ++i) {
		if (i == 0) result *= fibo(point[i] - 1);
		else {
			result *= fibo(point[i] - point[i - 1]-1);
		}
	}
	result *= fibo(N - point[M - 1]);

	cout << result << endl;

	return 0;
}

int fibo(int n) {
	if (n == 1 || n == 0) return 1;

	return fibo(n - 1) + fibo(n - 2);
}