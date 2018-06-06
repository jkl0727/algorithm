#include <stdio.h>
#include <malloc.h>

#define MAX_TABLE 100010;

class list {
public:
	int num;
	list *next;
	char name[25];

	list() {
		name[0] = NULL;
		next = NULL;
	}
};

list table[100010];
char poke[100010][25];
int N, M;


void strcpy(char *dst, char *sou) {
	int i = 0;
	while (sou[i] != NULL) {
		dst[i] = sou[i];
		i++;
	}
	dst[i] = NULL;
}

bool strcmp(char *dst, char *sou) {
	int i = 0;
	while (true) {
		if (dst[i] != sou[i])
			return 0;
		if (dst[i] == NULL)
			return 1;
		i++;
	}
}

long long hash_key(char *c) {
	long long hash = 0;
	int shift = 5821;

	while (*c != NULL) {
		hash = (hash  + (int)*c++) % MAX_TABLE;
	}

	return hash;
}

void make_hash(char *c, int i) {
	long long key = hash_key(c);

	if (table[key].name[0] == NULL) {
		strcpy(table[key].name, c);
		table[key].num = i;
	}
	else {
		list * temp = &table[key];
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new list;
		strcpy(temp->next->name, c);
		temp->next->num = i;
	}
}

long long dex_num(char *c) {
	int i = 0;
	long long ret = 0;
	while(c[i] != NULL){
		ret *= 10;
		ret += (int)c[i] % (int)'0';
		i++;
	}

	return ret;
}

int main(void) {
	char name[25];
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i) {
		scanf("%s", &name);
		strcpy(poke[i], name);
		make_hash(name, i);
	}

	for (int i = 0; i < M; ++i) {
		scanf("%s", &name);
		if ((int)name[0] - (int)'A' < 0) {
			long long num = dex_num(name);
			printf("%s\n", poke[num - 1]);
		}
		else {
			long long key = hash_key(name);
			list *temp = &(table[key]);
			while (true) {
				if (strcmp(name, temp->name)) {
					printf("%d\n", temp->num + 1);
					break;
				}
				else
					temp = temp->next;
			}
		}
	}

	return 0;
}