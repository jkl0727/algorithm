#include <iostream>
#include <vector>
#pragma warning(disable: 4996)
using namespace std;

class tower {
public:
	int tall, index;
};

int main(void) {
	int N;

	//freopen("index.txt", "r", stdin);
	cin >> N;
	int *result = new int[N];
	tower *arr = new tower[N];

	vector<tower> v;
	for (int i = 0; i < N; ++i) {
		result[i] = 0;
		cin >> arr[i].tall; arr[i].index = i;
		if (i == 0) v.push_back(arr[i]);
		else {
			while (!v.empty() && v.back().tall < arr[i].tall) {
				result[v.back().index] = i + 1;
				v.pop_back();
			}
			v.push_back(arr[i]);
		}
	}

	for (int i = 0; i < N; ++i) cout << result[i] << "\n";
	
	delete[] arr;
	delete[] result;
	return 0;
}