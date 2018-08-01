

const int MAX_LEN = (int)1e6;
int *ans, rig[MAX_LEN + 5], lef[MAX_LEN + 5];
int rI, lI, ansI;


extern int getNumber(int, int);

int numberOfCard(int *arr, int s, int e, int sel) {
	int ret, m;
	while (s <= e) {
		m = (s + e) / 2;
		arr[m] = getNumber(sel, m);
		if (!arr[m])
			e = m - 1;
		else
			s = m + 1,
			ret = m;
	}
	return ret;
}

int diffStartIdx(int ls, int le) {
	int lm, rm, ret = le + 1;
	while (ls <= le) {
		lm = (ls + le) / 2;
		rm = lm + ansI;
		if (rig[rm] == 0) rig[rm] = getNumber(1, rm);
		if (lef[lm] == 0) lef[lm] = getNumber(2, lm);
		if (rig[rm] == lef[lm]) ls = lm + 1;
		else ret = lm, le = lm - 1;
	}
	return ret;
}

int card_find(int user_ans[]) {
	ans = user_ans;
	rI = lI = ansI = 0;
	for (int i = 0; i <= MAX_LEN; ++i) {
		rig[i] = lef[i] = 0;
	}

	rI = numberOfCard(rig, 0, MAX_LEN - 1, 1);
	lI = numberOfCard(lef, 0, MAX_LEN - 1, 2);

	int ls = 0, le;

	while (ls <= lI) {
		le = ls + 2000;
		if (le > lI) le = lI;
		ls = diffStartIdx(ls, le);

		if (ls > le) continue;

		for (; ls <= lI;) {
			int rs = ls + ansI;
			if (rig[rs] == 0) rig[rs] = getNumber(1, rs);
			if (lef[ls] == 0) lef[ls] = getNumber(2, ls);
			if (rig[rs] == lef[ls]) break;
			ans[ansI++] = rig[rs];
		}
		ls++;
	}

	int ri = lI + ansI;
	while (ri < rI) {
		if (rig[ri] == 0) rig[ri] = getNumber(1, ri);
		ans[ansI++] = rig[ri++];
	}

	return ansI;
}