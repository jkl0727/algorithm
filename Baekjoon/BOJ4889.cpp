#include <iostream>
using namespace std;

#define push(X) (stack[++top] = (X))
#define pop (top--)
#define empty (top < 0)

char s[2001];
char stack[2001];
int top = -1, N;
int solve(void);

int main(void){
	//freopen("Text.txt", "r", stdin);
	int i = 1;
	while (1){
		scanf("%s", s);
		if (s[0]=='-') break;
		cout<<i<<". "<<solve()<<endl;
		i++;
	}
	
	return 0;
}

int solve(void){
	push(s[0]);
	int k = 1, cnt = 0;;
	while (s[k] != NULL){
		if (s[k]=='}'){
			if (stack[top]=='{') pop;
			else push(s[k]);
		}
		else push(s[k]);
		k++; 
	}
	int st = 0;
    int e = top;
	while (st<e){
		int flag = 1;
		if (stack[st]=='}') {
			cnt++;
			stack[st] ='{';
		}
		if (stack[e]=='{'){
			cnt++;
			stack[e] = '}';
		}
		if (stack[st]=='{' && stack[st+1]=='}' && stack[e]=='}' && stack[e-1]=='{'){
			st+=2; e-=2;
		}
		else if (stack[st]=='{' && stack[st+1]=='}'){
			st+=2;
		}
		else if (stack[e]=='}' && stack[e-1]=='{'){
			e-=2;
		}
		else{
			st++; e--;
		}
	}
	top = -1;
	return cnt;
}