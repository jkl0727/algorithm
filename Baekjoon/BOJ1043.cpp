#include <iostream>
using namespace std;

typedef struct{
	int num;
	int man[51];
}party;

int N, M, T;
int true_m[51];
int party_t[51];
party p[51];
void solve(void);

int main(void){
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	scanf("%d", &T);
	for (int i =0; i< T; i++){
		int t;
		scanf("%d", &t);
		true_m[t] = 1;
	}

	for (int i = 0; i<M; i++){
		scanf("%d", &p[i].num);
		for (int k = 0; k<p[i].num; k++){
			scanf("%d", &p[i].man[k]);
		}
	}
	solve();
	cout<<M<<endl;
	return 0;
}

void solve(void){
	int flag  = 1;
	while (flag){
		flag = 0;
		for (int i = 0; i<M; i++){
			for (int k = 0; k<p[i].num; k++){
				if (party_t[i] == 0 && true_m[p[i].man[k]]) {
					party_t[i] = 1;
					flag = 1;
				}
				else if (party_t[i] && true_m[p[i].man[k]]){
					
				}
				else if (party_t[i]) {
					true_m[p[i].man[k]] = 1;
					flag = 1;
				}
			}
		}
	}
	int temp = M;
	for (int i =0; i< temp; i++){
		M -= party_t[i];
	}
}