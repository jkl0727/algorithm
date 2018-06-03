#include <iostream>
#include <algorithm>
//#pragma warning(disable: 4996)
using namespace std;

class Sausage {
public:
	int l;
	int w;
};

bool operator <(const Sausage &a, const Sausage &b) {
	return a.l < b.l;
};

int main(void) {
	int N;
	//freopen("input.txt", "r", stdin);
	cin >> N;
	Sausage *s = new Sausage[N];
	for (int i = 0; i < N; ++i) {
		cin >> s[i].l >> s[i].w;
	}
	sort(s, s + N); 
	int result = 1; 
	int i = 0; 
	int t_i = 1;
	int go = 1; 
	int start_i = 0; int check = 1;
	int *flag = new int[N];
	for (int i = 0; i < N; ++i) { flag[i] = 0; }
	flag[0] = 1;
	while (go) {
		if (i + t_i >= N - 1) { if (check) break; i = start_i; t_i = 1; check = 1; }
		if (flag[i + t_i] == 0) {
			if (s[i].l > s[i + t_i].l || s[i].w > s[i + t_i].w) {
				if (check) { start_i = i + t_i; check = 0; result++;}
				t_i++; 
			}
			else {
				flag[i+t_i] = 1;
				i += t_i; t_i = 1;
			}
		}
		else {
			while (flag[i + t_i] != 0 && i + t_i <= N - 1) t_i++;
		}
	}

	cout << result << endl;
	return 0;
}