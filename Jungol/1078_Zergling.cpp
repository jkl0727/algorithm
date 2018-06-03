#include <iostream>
#include <string>
#include <queue>
//#pragma warning(disable: 4996)
using namespace std;

class axis{
public:
	int x, y;
	int time = 3;
};

axis kill_time(int **field, int X, int Y, axis s);

int main(void) {
	int X, Y;
	//freopen("input.txt", "r", stdin);
	cin >> X >> Y;
	int **field = new int*[Y];
	for (int i = 0; i < Y; ++i) {
		field[i] = new int[X];
	}
	string *s = new string[Y];
	for (int i = 0; i < Y; ++i) cin >> s[i];
	for (int y = 0; y < Y; ++y) {
		for (int x = 0; x < X; ++x) {
			field[y][x] = (int)s[y][x] % 48;
		}
	}
	axis p; 
	cin >> p.x >> p.y;
	axis start_p; start_p.x = p.x - 1; start_p.y = p.y - 1;
	field[start_p.y][start_p.x] = 0;
	axis result = kill_time(field, X, Y, start_p);

	cout << result.time << "\n" << result.x << endl;

	delete[] s;
	for (int i = 0; i < Y; ++i) {
		delete[] field[i];
	}
	delete[] field;

	return 0;
}

axis kill_time(int **field, int X, int Y, axis s) {
	int time = 3;
	int number = 0;
	axis result;
	queue<axis> q;
	q.push(s);

	while (!q.empty()) {
		int x[4] = { 0, 0, 1, -1 };
		int y[4] = { 1, -1, 0, 0 };
		axis temp = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			if ((temp.x + x[i] > X - 1) || (temp.x + x[i] < 0)
				|| (temp.y + y[i] > Y - 1) || (temp.y + y[i] < 0)) continue;
			if (field[temp.y + y[i]][temp.x + x[i]] == 1) {
				field[temp.y + y[i]][temp.x + x[i]] = 0;
				axis zeg; zeg.x = temp.x + x[i]; zeg.y = temp.y + y[i];
				zeg.time = temp.time + 1; time = zeg.time;
				q.push(zeg);
			}
		}
	}

	for (int y = 0; y < Y; ++y) {
		for (int x = 0; x < X; ++x) {
			if (field[y][x] == 1) {
				number++;
			}
		}
	}
	result.time = time; result.x = number;
	return result;
}