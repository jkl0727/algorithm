#include <stdio.h>

#define MAX_STR 100000
#define MAX_CHAR 80
#define MAX_A	26

class node {
public:
	node *child[MAX_A];
	bool finish;
	int n_child;
	void m_child_init(void) {
		for (int i = 0; i < MAX_A; ++i) {
			child[i] = NULL;
		}
	};

	node() {
		finish = false;
		n_child = 0;
		m_child_init();
	}
	~node() {
		for (int i = 0; i < MAX_A; ++i) {
			delete child[i];
		}
	}
};

node *tri = NULL;
char dic[MAX_STR + 10][MAX_CHAR + 10];

void init(void) {
	if (tri != NULL)
		delete tri;
	
	tri = new node();
}

void make_tri(char * str) {
	node *temp = tri;
	while (*str != NULL) {
		if (temp->child[*str % 'a'] == NULL) {
			temp->child[*str % 'a'] = new node;
			temp->n_child++;
		}
		temp = temp->child[*str % 'a'];
		str++;
	}
	temp->finish = true;
}

/*int check_overlap(node *temp, char c) {
	for (int i = 0; i < MAX_A; ++i) {
		if (i == c % 'a')
			continue;
		if (temp->child[i] != NULL)
			return 1;
	}
	return 0;
} */

int button_avg(char *str) {
	int ret = 0;
	node *temp = tri->child[*str % 'a'];
	while (*str != NULL) {
		if (temp->n_child > 1 || (temp->finish && temp->n_child < 2))
			ret++;
		str++;
		temp = temp->child[*str % 'a'];
	}
	return ret;
}

int main(void) {

	while (true) {
		int N = 0;
		float sum = 0;
		float ret = 0;

		scanf("%d", &N);
		if (N < 1 || N > MAX_STR)
			break;
		
		init();
		
		for (int i = 0; i < N; ++i) {
			scanf("%s", dic[i]);
			make_tri(dic[i]);
		}

		for (int i = 0; i < N; ++i) {
			sum += button_avg(dic[i]);
		}
	
		printf("%.2f\n", sum / N);
	}
	return 0;
}