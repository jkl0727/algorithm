#include <stdio.h>

class tree {
public:
	tree * m_num[10];
	int m_exist;
	
	tree() {
		m_exist = 0;
		for (int i = 0; i < 10; ++i) {
			m_num[i] = NULL;
		}
	}
};

int T, ret;
tree tri;
char phone_num[10000 + 10][11];

void make_tri(tree *t, const char * str) {
	while (true) {
		if (*str == NULL) {
			t->m_exist = 1;
			return;
		}
		int key = (int)(*str % '0');
		if (t->m_num[key] == NULL)
			t->m_num[key] = new tree;
		t = t->m_num[key];
		str++;
	}
}

bool find_num(tree *t, const char * str) {
	while (true) {
		if (*str == NULL) 
			return true;
		if (t->m_exist)
			return false;

		int key = (int)(*str % '0');
		t = t->m_num[key];
		str++;
	}
}

void delete_num(tree *t, const char * str) {
	while (true) {
		if (*str == NULL) {
			t->m_exist = 0;
			return;
		}
		int key = (int)(*str % '0');
		t = t->m_num[key];
		str++;
	}
}

int main(void) {

	scanf("%d", &T);

	for (int t = 0; t < T; ++t) {
		int N; ret = 0;
		scanf("%d", &N);
		
		for (int n = 0; n < N; ++n) {
			scanf("%s", phone_num[n]);
			make_tri(&tri, phone_num[n]);
		}

		for (int n = 0; n < N; ++n) {
			if (!find_num(&tri, phone_num[n])) {
				ret = 1;
				break;
			}
		}

		for (int n = 0; n < N; ++n) {
			delete_num(&tri, phone_num[n]);
		}

		if (!ret)
			printf("%s", "YES\n");
		else
			printf("%s", "NO\n");
	}
}