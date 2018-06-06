#include <iostream>
using namespace std;

#define Enqueue(X) (queue[en++] = (X)) 
#define Dequeue(X) ((X) = queue[fro++])
#define Empty (fro >= en)



int N, K, fro, en;
int queue[1000000];
int visit[100001];
int solve(void);

int main(void){

	scanf("%d %d", &N, &K);

	cout<<solve()<<endl;
	return 0;
}

int solve(void){
	int temp;
	Enqueue(N);
	visit[N] = 1;
	while (!Empty){
		Dequeue(temp);
		if (temp==K) return visit[temp] - 1;
		int b = temp-1;
		int f = temp+1;
		int j = 2*temp;
		if (b>0&&visit[b] == 0){
			visit[b] = visit[temp] + 1;
			Enqueue(b);
		}
		if (f<=100000&&visit[f] == 0){
			visit[f] = visit[temp]+1;
			Enqueue(f);
		}
		if (j<=100000&&visit[j] == 0){
			visit[j] = visit[temp]+1;
			Enqueue(j);
		}
	}
}