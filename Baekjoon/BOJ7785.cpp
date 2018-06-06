#include <iostream>
#include <string>
using namespace std;

int N, e_last, l_last;
string enter_heap[1000000 + 10];
string leave_heap[1000000 + 10];
void swap(string *a, string *b);
void push(char c, string s);
int strcmp(string a, string b);
int empty(char c);
string pop(char c);

int main(void) {
	scanf("%d", &N);
	register int i;
	for (i = 0; i < N; i++) {

		string name; string mov;
		cin >> name >> mov;
		push(mov[0], name);
	}

	while (!empty('e')) {
		if (!empty('l') && strcmp(enter_heap[1], leave_heap[1]) == 0) {
			pop('e'); pop('l');
		}
		else {
			cout << pop('e') << endl;
		}
	}

	return 0;
}

void swap(string *a, string *b) {
	string temp = *a;
	*a = *b;
	*b = temp;
}

void push(char c, string s) {
	string* heap; int last;
	if (c == 'e') {
		heap = enter_heap;
		last = ++e_last;
	}
	else {
		heap = leave_heap;
		last = ++l_last;
	}
	
	heap[last] = s;
	register int ch = last, p = ch/2;
	while (p > 0) {
		if (strcmp(heap[ch], heap[p]) == 1) swap(&heap[ch], &heap[p]);
		else break;
		ch = p; p = ch / 2;
	}
}

int empty(char c) {
	int ret;
	if (c == 'e') {
		if (e_last == 0) ret = 1;
		else ret = 0;
	}
	else {
		if (l_last == 0) ret = 1;
		else ret = 0;
	}
	return ret;
}

string pop(char c) {
	string* heap; int last;
	if (c == 'e') {
		heap = enter_heap;
		last = e_last--;
	}
	else {
		heap = leave_heap;
		last = l_last--;
	}
	swap(&heap[1], &heap[last + 1]);
	register int i = 1;
	while (2 * i <= last) {
		int max = i, l = max * 2, r = l + 1;
		if (strcmp(heap[l], heap[max]) == 1) max = l;
		if (strcmp(heap[r], heap[max]) == 1 && r <= last) max = r;
		if (max != i) swap(&heap[max], &heap[i]);
		else break;
		i = max;
	}
	return heap[last + 1];
}

int strcmp(string a, string b) {
	register int i = 0;
	while (a[i] != NULL || b[i] != NULL) {
		if (a[i] == NULL) return -1;
		else if (b[i] == NULL) return 1;
		else if ((int)a[i] > (int)b[i]) return 1;
		else if ((int)a[i] < (int)b[i]) return -1;
		i++;
	}
	return 0;
}