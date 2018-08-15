#include <stdio.h>

struct puzzle {
	int id , same;
	int num[4];
};

int N, M, T, S, NN;
int p_i = 0;
int check[2510] = { 0, };
int p_idx[51][51];
int wrong_piece[5];
puzzle piece[2510];


int encode(char *str) {
	int ret = 0, temp;

	for (int i = 1; i < M - 1; ++i) {
		if (str[i] == '0') temp = 1;
		else if (str[i] == 'M') temp = 2;
		else temp = 0;

		ret = ret * 3 + temp;
	}

	return ret;
}

void input(void) {
	int i, j, k;
	char str[20];
	scanf("%d %d %d", &N, &M, &T);
	NN = N * N;
	for (i = 1, S = 1; i < M - 1; i++) S *= 3;

	for (int k = 0; k < NN + T; ++k) {
		piece[k].id = k;
		piece[k].same = 0;

		for (int i = 0; i < 4; ++i) {
			scanf("%s", str);

			int en = encode(str);
			if (i < 2) {
				piece[k].num[i] = en;
			}
			else
				piece[k].num[i] = S - en - 1;
		}
	}
}

int arrange_piece(int layer) {
	if (layer >= NN)
		return 1;

	int row = layer / N; int col = layer % N;
	for (int i = 0; i < NN + T; ++i) {

		if (check[i])
			continue;
		if (row && piece[i].num[3] != piece[p_idx[row - 1][col]].num[1])
			continue;
		if (col && piece[i].num[2] != piece[p_idx[row][col - 1]].num[0])
			continue;

		p_idx[row][col] = i;
		check[i] = 1;

		if (arrange_piece(layer + 1))
			return 1;

		check[i] = 0;
	}

	return 0;
}

int main(void) {

	input();

	int i, k;
	for (i = 0; i < NN + T; ++i) {
		for (k = 0; k < NN + T; ++k) {
			if (piece[i].num[2] == piece[k].num[0])
				piece[i].same++;
			if (piece[i].num[3] == piece[k].num[1])
				piece[i].same++;
		}
	}

	for (int t = 0; t <= T; ++t) {
		for (i = 0; i < NN + T; ++i) {
			if (piece[i].same == t)
			{
				p_idx[0][0] = i;
				check[i] = 1;
				if(arrange_piece(1)) break;
				check[i] = 0;
			}
		}
		if (i < NN + T) break;
	}
	
	int r, c;
	scanf("%d %d", &r, &c);
	printf("%d\n", p_idx[r][c]);
	
	for (i = 0; i < NN + T; ++i)
		if(check[i] == 0)
			printf("%d ", piece[i].id);
	

	return 0;
}