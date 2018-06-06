#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 300005

int N,M,C,A[MAXN],ans;
vector <int> pos[10001];

int main()
{
	int i,l,r,cnt,c;
	scanf("%d%d",&N,&C);
	for (i=1;i<=N;i++) scanf("%d",A+i), pos[A[i]].push_back(i);
	for (scanf("%d",&M);M--;){
		scanf("%d%d",&l,&r);
		for (i=100;i;i--){
			c = A[l+rand()%(r-l+1)];
			cnt = upper_bound(pos[c].begin(),pos[c].end(),r)-lower_bound(pos[c].begin(),pos[c].end(),l);
			if (cnt > (r-l+1)/2) break;
		}
		if (i) printf("yes %d\n",c);
		else puts("no");
	}
}