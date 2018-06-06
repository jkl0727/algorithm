#include <iostream>
#include <queue>
using namespace std;

struct node {
	int y, x;
};

int main(void) {
	//freopen("7576.txt", "r", stdin);
	int M, N;
	int r[4] = { -1, 0, 1, 0 };
	int c[4] = { 0, 1, 0 ,-1 };
	int arr[1000][1000];
	int result = 0;
	int flag = 1;
	queue<node> q;

	cin >> M >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
			if (arr[y][x] == 0) flag = 0;
			if (arr[y][x] == 1) {
				node temp; temp.y = y; temp.x = x;
				q.push(temp);
			}
		}
	}

	if (flag) {
		cout << result << "\n";
		return 0;
	}

	while (!q.empty()) {
		node temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int y = temp.y + r[i]; int x = temp.x + c[i];
			if (y > N - 1 || x > M - 1 || y < 0 || x < 0) continue;
			if (arr[y][x] == 0) {
				arr[y][x] = 1+ arr[temp.y][temp.x];
				node put; put.y = y; put.x = x;
				q.push(put);
			}
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (arr[y][x] == 0) {
				int temp = -1;
				cout << temp << "\n";
				return 0;
			}
			if (arr[y][x] > 0 && result < arr[y][x]) result = arr[y][x];
		}
	}
	cout << result -1 << "\n";
	
	return 0;
}