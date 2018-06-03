#include <iostream>
#include <queue>
#pragma warning(disable: 4996)
using namespace std;

#define SOURCE 1

int main(void) {
	int E, V;
	int result = 0;
	int flow[220][220] = { 0, };
	freopen("input.txt", "r", stdin);
	cin >> E >> V; int sink = V;
	for (int i = 1; i <= E; i++) {
		int s, e, a;
		cin >> s >> e >> a;
		flow[s][e] +=a;
	}


	while(true){
		int parent[220] = { 0, };
		queue<int> q;
		q.push(SOURCE);
		parent[SOURCE] = SOURCE;
		while (!q.empty() && parent[sink] == 0) {
			int s = q.front();
			q.pop();

			for (int i = 1; i <= V; ++i) {
				if (i == s) continue;
				if (flow[s][i] > 0 && parent[i] == 0) {
					q.push(i);
					parent[i] = s;
				}
			}
		}

		if (parent[sink] == 0) break;

		int water = 0x7fffffff;
		for (int k = sink; k != SOURCE; k = parent[k]) {
			water = min(water, flow[parent[k]][k]);
		}
		for (int k = sink; k != SOURCE; k = parent[k]) {
			flow[parent[k]][k] -= water;
			flow[k][parent[k]] += water;
		}
		result += water;
	}
	cout << result << endl;

	return 0;
}