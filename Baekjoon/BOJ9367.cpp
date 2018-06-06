#include <iostream>
using namespace std;

typedef struct {
	char name[50];
	int car;
	unsigned long long int bill;
	int inc;
}info;

typedef struct {
	char name[50];
	int mon, b, k, re;
}info_car;

int T, N, M, last = 1;
info_car C[510];
info ret[510];
int index[510];
int find(char *c);
int find_car(char *c);
int strcmp(char *a, char *b);
int strcom(char *a, char *b);
void sort(void);

int main(void) {
	scanf("%d", &T);
	register int i;
	while (T--) {
		scanf("%d %d", &N, &M);
		for (i = 1; i <= N; i++) {
			scanf("%s %d %d %d", C[i].name, &C[i].mon, &C[i].b, &C[i].k);
			
		}
		for (i = 1; i <= last; i++) {
			ret[i].name[0] = NULL;
			ret[i].car = 0;
			ret[i].bill = 0;
			ret[i].inc = 0;
		}
		last = 1;
		for (i = 0; i < M; i++) {
			int temp; char name[50]; char e; char c[50];
			scanf("%d", &temp);
			scanf("%s %c", name, &e);
			int k = find(name);
			if (e == 'p') {
				scanf("%s", c);
				int t = find_car(c);
				if (ret[k].car || ret[k].inc) {
					ret[k].inc = 1;
					continue;
				}
				ret[k].car = t;
				ret[k].bill += C[ret[k].car].b;
			}
			else if (e == 'r') {
				scanf("%d", &temp);
				if (ret[k].car == 0 || ret[k].inc) {
					ret[k].inc = 1;
					continue;
				}
				ret[k].bill += C[ret[k].car].k * temp;
				ret[k].car = 0;
			}
			else {
				scanf("%d", &temp);
				if (ret[k].car == 0 || ret[k].inc) {
					ret[k].inc = 1;
					continue;
				}
				ret[k].bill += (int)((double)C[ret[k].car].mon * ((double)temp/100));
				if (C[ret[k].car].mon * temp % 100) ret[k].bill++;
			}
		}
		sort();
		for (i = 1; i < last; i++) {
			printf("%s", ret[index[i]].name);
			if (ret[index[i]].inc || ret[index[i]].car) printf(" INCONSISTENT\n");
			else printf(" %d\n", ret[index[i]].bill);
		}
	}

	return 0;
}

int find(char *c) {
	register int i = 1;
	for (; i <= last; i++) {
		if (strcmp(c, ret[i].name)) {
			return i;
		}
		else if (i == last) {
			register int k = 0;
			while (c[k] != NULL) {
				ret[i].name[k] = c[k];
				k++;
			}
			ret[i].name[k] = NULL;
			ret[i].bill = 0;
			ret[i].car = 0;
			index[i] = last;
			last++;
			return i;
		}
	}
}

int find_car(char *c) {
	register int i = 1;
	for (; i <= N; i++) {
		if (strcmp(c, C[i].name)) {
			return i;
		}
	}
	return 0;
}


int strcmp(char *a, char *b) {
	register int i = 0;
	while (a[i] != NULL || b[i] != NULL) {
		if (a[i] != b[i]) return 0;
		i++;
	}
	return 1;
}

int strcom(char *a, char *b) {
	register int i = 0;
	while (a[i] != NULL || b[i] != NULL) {
		if (a[i] == NULL) return 0;
		if (b[i] == NULL) return 1;
		if ((int)a[i] < (int)b[i]) return 0;
		else if ((int)a[i] > (int)b[i]) return 1;
		i++;
	}
	return 0;
}

void sort(void) {
	register int i;
	for (i = 1; i < last - 1; i++) {
		int key = i;
		for (int k = i+1; k < last; k++) {
			if (strcom(ret[index[key]].name, ret[index[k]].name)) {
				key = k;
			}
		}
		int temp = index[key];
		index[key] = index[i];
		index[i] = temp;
	}
}