#include <iostream>
using namespace std;


int N, M, INF_flag, result;
int row[4] = { 0,0,-1,1 };
int col[4] = { 1,-1,0,0 };
int dp[55][55];
int visit[55][55];
char map[55][55];
void dfs(int x, int y);
int solve(int x, int y);
int MAX(int x, int y);

int main(void) {
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++) {
		scanf("%s", &map[y]);
	}

	dfs(0, 0);
	if (INF_flag) {
		cout << "-1" << endl;
	}
	else {
		cout << solve(0,0) << endl;
	}
	return 0;
}

void dfs(int x, int y) {
	visit[y][x] = -1;
	if (map[y][x] == 'H') {
		visit[y][x] = 1;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int n = map[y][x] % '0';
		int nx = x + n*row[i];
		int ny = y + n*col[i];
		if (nx < 0 || ny < 0 || nx > M - 1 || ny > N - 1)
			continue;
		if (visit[ny][nx] == -1) {
			INF_flag = 1;
			return;
		}
		else if (!visit[ny][nx]) dfs(nx, ny);
	}
	visit[y][x] = 1;
}

int solve(int x, int y) {
	if (x < 0 || y < 0 || x > M - 1 || y > N - 1
		|| map[y][x] == 'H') return 0;
	if (dp[y][x]) return dp[y][x];
	dp[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int n = map[y][x] % '0';
		int nx = x + n*row[i];
		int ny = y + n*col[i];
		dp[y][x] = MAX(dp[y][x], solve(nx, ny) + 1);
	}
	return dp[y][x];
}

int MAX(int x, int y) {
	if (x > y) return x;
	else return y;
}