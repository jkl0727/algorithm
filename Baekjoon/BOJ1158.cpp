#include <stdio.h>
#include <malloc.h>

typedef struct _list{
	int i;
	_list *next = NULL;
}list;

int N, M, cnt;
list first;

int main(void) {
	int i;
	list *beforelist;

	scanf("%d %d", &N, &M);

	first.i = 1;
	beforelist = &first;

	for (i = 2; i <= N; ++i) {
		list * temp = new list;
		temp->i = i;
		beforelist->next = temp;
		beforelist = temp;
	}
	beforelist->next = &first;

	printf("<");

	list *temp = &first;
	i = 1;
	while (true) {
		if (i == M) {
			printf("%d", temp->i);
			beforelist->next = temp->next;
			i = 1;
			cnt++;
			if (cnt == N) break;
			else {
				printf(", ");
				temp = temp->next;
				continue;
			}
		}
		i++;
		beforelist = temp;
		temp = temp->next;
	}
	printf(">\n");

	return 0;
}