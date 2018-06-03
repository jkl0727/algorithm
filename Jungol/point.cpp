#include <iostream>
using namespace std;

class point {
public:
	int x, y;
};

class line {
public:
	point p1, p2;
};

int intersection(line L1, line L2);
int vec_direction(point A, point B, point C);

int main(void) {
	int n;
	int cross_point = 0;
	cin >> n;
	line *L = new line[n];

	for (int i = 0; i < n; i++) {
		point p1, p2;
		cin >> p1.x >> p1.y >> p2.x >> p2.y;
		L[i].p1 = p1; L[i].p2 = p2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (intersection(L[i], L[j])) cross_point++;
		}
	}

	cout << cross_point << "\n";
	delete[] L;

	return 0;
}

int intersection(line L1, line L2) {
	int inter = 0;
	if ((vec_direction(L1.p1, L1.p2, L2.p1)*vec_direction(L1.p1, L1.p2, L2.p2) < 1) &&
		(vec_direction(L2.p1, L2.p2, L1.p1)*vec_direction(L2.p1, L2.p2, L1.p2) < 1)) {
		inter = 1;
	}
	else inter = 0;

	return inter;
}

int vec_direction(point A, point B, point C) {
	int dxAB = B.x - A.x;
	int dyAB = B.y - A.y;
	int dxAC = C.x - A.x;
	int dyAC = C.y - A.y;
	int dir;

	if (dxAB*dyAC < dyAB*dxAC) dir = 1;
	else if (dxAB*dyAC > dyAB*dxAC) dir = -1;
	else {
		if (dxAB == 0 || dyAB == 0) dir = 0;
		else if (dxAB*dyAC < 0 || dxAC*dyAB) dir = -1;
		else if (dxAB*dxAB + dyAB*dyAB >= dxAC*dxAC + dyAC*dyAC) dir = 0;
		else dir = 1;
	}
	return dir;
}