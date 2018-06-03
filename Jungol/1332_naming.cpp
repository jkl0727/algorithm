#include <iostream>
#include <string>
#include <stack>
#pragma warning(disable: 4996)
using namespace std;

void make_pi(string s, int* pi, int N);

int main(void) {
	string s;
	
	//freopen("input.txt", "r", stdin);
	cin >> s;
	int N = s.size();
	int *pi = new int[N + 1];
	
	make_pi(s, pi, N);
    
	int i = N;
	stack<int> c; c.push(N);
	while (pi[i] > 0) {
		c.push(pi[i]);
		i = pi[i];
	}
	
	while (!c.empty()) {
		cout << c.top() << " ";
		c.pop();
	}
	delete[] pi;
	return 0;
}

void make_pi(string s, int* pi, int N) {
	int i = 0; int j = -1; pi[0] = -1;
	while (i < N) {
		if ( j == -1 || s[i] == s[j]) {
			i++; j++; pi[i] = j;
		}
		else {
			j = pi[j];
		}
	}
}