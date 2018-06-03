#include<iostream>
using namespace std;

#define N 100000

int main(void) {
	int y;
	int sequence[N] = { 0, };
	cin >> y;
	sequence[0] = 1; sequence[1] = 1;
	for (int i = 2; i <= y; ++i) {
		sequence[i] = sequence[i - 1] + 2*sequence[i - 2];
		sequence[i] = sequence[i] % 20100529;
	}
	cout << sequence[y] << endl;
	return 0;
}