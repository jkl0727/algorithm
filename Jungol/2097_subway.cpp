#include <iostream>
#include <queue>
#include <stack>
#pragma warning(disable : 4996)

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

class vertex {
public:
	int color = WHITE;
	int w = 100000;
	int bef_v;
	int i;
};


struct compare_v {
	bool operator()(const vertex &l, const vertex &r) {
		return l.w > r.w;
	}
};
struct compare {
	bool operator()(const int &l, const int &r) {
		return l > r;
	}
};

void short_path(vertex *v, int **e, int N);

int main(void) {
	int N, M;

	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	int **e = new int*[N];
	for (int i = 0; i < N; ++i) {
		e[i] = new int[N];
	}
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> e[y][x];
		}
	}

	vertex *v = new vertex[N];
	v[0].w = 0;
	for (int i = 0; i < N; i++) v[i].i = i;

	short_path(v, e, N);

	stack<int> m_Q;
	int i = M - 1;
	while (i != 0) {
		m_Q.push(v[i].bef_v);
		i = v[i].bef_v - 1;
	}
	cout << v[M - 1].w << endl;
	while (!m_Q.empty()) {
		cout << m_Q.top() << " "; m_Q.pop();
	}
	cout << M << "\n";

	delete[] v;
	for (int i = 0; i < N; ++i) delete[] e[i];
	delete[] e;

	return 0;
}

void short_path(vertex *v, int **e, int N) {
	priority_queue<vertex, vector<vertex>, compare_v> m_Q;
	m_Q.push(v[0]);
	while (!m_Q.empty()) {
		vertex temp = m_Q.top(); m_Q.pop(); temp.color = GRAY;
		//for (int i = 0; i < N; i++) { cout << v[i].w << " "; } cout << "\n";
		for (int i = 0; i < N; ++i) {
			if (e[temp.i][i] > 0 && v[i].color != BLACK) {
				if (v[i].w >= e[temp.i][i] + v[temp.i].w) {
					v[i].w = e[temp.i][i] + v[temp.i].w;
					v[i].bef_v = temp.i + 1;
					if (v[i].color == WHITE) {
						m_Q.push(v[i]);
					}
				}
			}
		}
		temp.color = BLACK;
	}
}