#include <iostream>
using namespace std;

typedef struct {
	int lin1;
	int lin2;
}power;

int N, max_len;
power pl[100000 + 10];
power lis[100000 + 10];
void sort(void);
void find_lis(void);
int binary_upper(int e, power d);

int main(void) {

	//freopen("1911_L.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &pl[i].lin1, &pl[i].lin2);
	}
	sort();
	find_lis();
	cout << N - max_len << endl;
	return 0;
}


void sort(void) {
	for (int i = 0; i < N; i++) {
		int key = i;
		for (int j = i + 1; j <= N; j++) {
			if (pl[key].lin1 > pl[j].lin1) key = j;
		}
		power temp = pl[key];
		pl[key] = pl[i];
		pl[i] = temp;
	}
}


int binary_upper(int e, power d) {
	int s = 0, len;
	while (s <= e) {
		int m = (s + e) / 2;
		if (lis[m].lin1 <= d.lin1 && lis[m].lin2 <= d.lin2) {
			len = m;
			s = m + 1;
		}
		else e = m - 1;
	}
	return len + 1;
}

void find_lis(void){

	for (int i = 1; i <= N; i++) {
		int len = binary_upper(max_len, pl[i]);
		lis[len] = pl[i];
		if (max_len < len) max_len = len;
	}

}