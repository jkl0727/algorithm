#include <iostream>
using namespace std;

int N, num, l, cn = 1, result = 0x3fffffff;
int cnt;
int start_y, start_x;
int row[8] ={ 0, 0, 1, -1, 1, -1, -1, 1 };
int col[8] ={ 1, -1, 0, 0, 1, 1, -1, -1 };
char map[51][51];
int range[51*51];
int stress[51][51];
int visit[51][51];
int solve(void);
void dfs(int s, int e, int y, int x);
void sort(void);

int main(void) {
	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		scanf("%s", &map[y]);
		for (int x = 0; x < N; x++){
			if (map[y][x]=='P') {
				start_y = y; start_x = x;
				visit[y][x] = 1;
			}
			if (map[y][x]=='K') num++;
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &stress[y][x]);
			range[y*N+x] = stress[y][x];
		}
	}
	sort();

	for (int i = 1; i < N*N; i++) {
		if (range[i-1]!=range[i]) range[cn++] = range[i];
	}

	printf("%d\n", solve());

	return 0;
}

void sort(void) {
	for (int i = 0; i < N*N-1; i++) {
		int key = i;
		for (int k = i+1; k < N*N; k++) {
			if (range[key] > range[k]) key = k;
		}
		int temp = range[key];
		range[key] = range[i];
		range[i] = temp;
	}
}

int solve(void) {
	int s = 0, e = 0;
	while (1) {
		cnt = 0;
		if (e > cn-1||s > e) break;
		for (int y =0; y<N; y++){
			for (int x =0; x<N; x++){
				visit[y][x] = 0;
			}
		}
		visit[start_y][start_x] = 1;
		dfs(range[s], range[e], start_y, start_x);
		if (num==cnt){
			if (result > range[e]-range[s]) result = range[e]-range[s];
			s++;
		}
		else e++;
	}

	return result;
}

void dfs(int s, int e, int y, int x) {
	if (stress[y][x] > e||stress[y][x]<s) return;
	for (int i = 0; i < 8; i++) {
		int t_y = y+col[i];
		int t_x = x+row[i];
		if (t_y < 0||t_x < 0||t_y>=N||t_x>=N) continue;
		if (stress[t_y][t_x] > e||stress[t_y][t_x]<s) continue;
		if (visit[t_y][t_x]==1) continue;
		if (map[t_y][t_x]=='K') cnt++;
		visit[t_y][t_x] = 1;
		dfs(s, e, t_y, t_x);
	}
}