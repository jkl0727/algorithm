#include <iostream>
#include <vector>
#pragma warning(disable: 4996)
using namespace std;

class top {
public:
	int t, i;
};

int main(void) {
	int N; 
	//freopen("input.txt", "r", stdin);
	cin >> N;
	top *arr = new top[N]; int *result = new int[N];
	for (int i = 0; i < N; ++i) {
		cin >> arr[i].t; arr[i].i = i; result[i] = 0;
	}
	
	vector<top> v; v.push_back(arr[N - 1]);
	for (int i = N - 2; i > -1; --i) {
		if (v.back().t < arr[i].t) {
			while (!v.empty() && v.back().t < arr[i].t) {
				result[v.back().i] = arr[i].i + 1;
				v.pop_back();
			}
			v.push_back(arr[i]);
		}
		else {
			v.push_back(arr[i]);
		}
	}

	for (int i = 0; i < N; ++i) {
		cout << result[i] << " ";
	}

	return 0;
}