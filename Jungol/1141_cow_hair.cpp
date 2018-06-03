#include <iostream>
#include <vector>
#pragma warning(disable: 4996)
using namespace std;

int main(void) {
	int N;
	unsigned int result = 0;
	//freopen("input.txt", "r", stdin);
	
	cin >> N;
	int *arr = new int[N];
	int t_i = 0; int tall;
	for (int i = 0; i < N; ++i) {
		cin >> tall;
		while (t_i > 0 && arr[t_i-1] <= tall) t_i--;
		result += t_i;
		arr[t_i++] = tall;
	}

	cout << result << "\n";
	delete[] arr;
	return 0;
}
