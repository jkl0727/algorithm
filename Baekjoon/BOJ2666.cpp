#include <iostream>
using namespace std;
 
#define abs(X) ((X >0) ? (X) : ((-1)*(X)))
 
int N, M, mov = 0x7fffffff;
int op[2];
int closet[20];
void dfs(int i, int w, int op1, int op2);
 
int main(void){
 
    //freopen("1913_O.txt", "r", stdin);
    scanf("%d %d %d %d", &N, &op[0], &op[1], &M);
    for (int i = 0; i < M; i++){
        scanf("%d", closet + i);
    }
    dfs(0, 0, op[0], op[1]);
    cout << mov << endl;
 
    return 0;
}
 
void dfs(int i, int w, int op1, int op2){
    if (i >= M){
        if (w < mov) mov = w;
        return;
    }
    int t_w = w + abs(closet[i] - op1);
    dfs(i + 1, t_w, closet[i], op2);
    t_w = w + abs(closet[i] - op2);
    dfs(i + 1, t_w, op1, closet[i]);
}