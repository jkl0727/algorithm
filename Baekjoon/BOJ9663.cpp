#include <iostream>
using namespace std;

int N, cnt;
int cross1[31];
int cross2[31];
int col[16];
void dfs(int n);
int check(int y, int x);

int main(void){

	cin >> N;
	dfs(1);
	cout << cnt << endl;

	return 0;
}

void dfs(int n) {
	if (n > N) {
		cnt++;
		return;
	}

	for (int x = 1; x <= N; x++) {
		if (check(n, x)) continue;
		cross1[N + x - n] = 1;
		cross2[x + n] = 1;
		col[x] = 1;
		dfs(n + 1);
		cross1[N + x - n] = 0;
		cross2[x + n] = 0;
		col[x] = 0;
	}
}

int check(int y, int x) {
	if (cross1[N + x - y] == 1) return 1;
	if (cross2[x + y] == 1) return 1;
	if (col[x] == 1) return 1;
	return 0;
}