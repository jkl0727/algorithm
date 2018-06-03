#include <iostream>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

int DP(int *L, int *R, int **dp, int N);
int main(void) {
	int N;
	freopen("input.txt", "r", stdin);
	cin >> N;

	int *L = new int[N + 2];
	int *R = new int[N + 2];
	int **dp = new int*[N + 2];
	for (int i = 0; i < N + 2; ++i) {
		dp[i] = new int[N + 2];
	}
	for (int i = 1; i < N + 1; ++i) {
		cin >> L[i];
	}
	for (int i = 1; i < N + 1; ++i) {
		cin >> R[i];
	}

	cout << DP(L, R, dp, N) << endl;

	delete[] L; delete[] R;
	for (int i = 0; i < N + 2; i++) {
		delete dp[i];
	}
	delete[] dp;
	return 0;
}

int DP(int *L, int *R, int **dp, int N) {
	int Max = 0;
	for (int i = 1; i <= N + 1; i++) {
		dp[0][i] = -1;
	}
	for (int i = 1; i <= N + 1; i++) {
		dp[i][0] = 0;
	}
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j <= N + 1; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
			if (dp[i][j - 1] != -1 && L[i] > R[j-1])
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + R[j-1]);
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= N + 1; i++) {
		if (Max < dp[N][i]) Max = dp[N][i];
	}
	return Max;
}