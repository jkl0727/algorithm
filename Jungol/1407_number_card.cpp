#include <iostream>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

int fibo(int n);
int check_case(string s);

int main(void) {
	string s;
	
	//freopen("input.txt", "r", stdin);
	cin >> s;
	
	int result = check_case(s);
	cout << result << endl;

	return 0;
}

int check_case(string s) {
	int result = 1, i = 0;
	int n = s.size();
	int temp = 0; int z_flag = 0;

	while (i < n - 1) {
		int num = (int)s[i] % 48;
		if (num > 3) {
			result *= fibo(i + 1 - temp);
			temp = i + 1;
		}
		else if (num == 3) {
			if (i + 1 < n && (int)s[i + 1] % 48 > 4) {
				result *= fibo(i + 1 - temp);
				temp = i + 1;
			}
		}
		else if (num == 0) {
			if ((int)s[i-1] % 48 > 3) {
				return 0;
			}
			else {
				temp = i + 1;
			}
		}
		i++;
	}
	result *= fibo(n - temp);

	return result;
}

int fibo(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	return fibo(n - 1) + fibo(n - 2);
}