#include <iostream>
using namespace std;
//#pragma warning(disable: 4996)

int divide_paper(int **map, int s_x, int s_y, int N, int &white, int &blue);

int main(void) {
	int N;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> N;
	int **map = new int*[N];
	for (int i = 0; i < N; ++i) {
		map[i] = new int[N];
	}
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> map[y][x];
		}
	}
	int white = 0; int blue = 0; int flag = 0;
	divide_paper(map, 0, 0, N, white, blue);
	cout << white << "\n" << blue << endl;

	for (int i = 0; i < N; i++) {
		delete[] map[i];
	}
	delete[] map;
	return 0;
}

int divide_paper(int **map, int s_x, int s_y, int N, int &white, int &blue) {
	int result = 0; int overlap = 0; int t_b = 0; int t_w = 0;
	if (N < 2) {
		if (map[s_y][s_x] == 1) result = 1;
		else result = 0;
		return result;
	}
	else {
		int x[4] = { s_x, s_x + N / 2, s_x, s_x + N / 2 };
		int y[4] = { s_y, s_y, s_y + N / 2, s_y + N / 2 };
		for (int i = 0; i < 4; i++) {
			int temp = divide_paper(map, x[i], y[i], N / 2, white, blue);
			if (temp == 1) t_b++;
			else if (temp == 0) t_w++;
			else overlap++;
		}
	}

	if (t_b == 4) {
		result = 1; overlap = 0;
	}
	else if (t_w == 4) {
		result = 0; overlap = 0;
	}
	else if(overlap < 4){
		blue += t_b;
		white += t_w;
		result = -1;
	}
	else result = -1;

	return result;
}