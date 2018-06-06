#include <stdio.h>
#define COL 1
#define ROW 0

typedef struct _path
{
	int sel;
	int pos;
	int cnt;
}PATH;

int map[5][5];
PATH p[8];
PATH ans[8];
int min=8;
void solve(int);
int checAns(void);
int main(void)
{
	int i, j;
	for (i=1; i < 5; i++)
	for (j=1; j < 5; j++)
		scanf("%d", &map[i][j]);
	solve(0);
	printf("%d\n", min);
	for (i=0; i < min; i++)
		printf("%d %d %d\n", ans[i].sel+1, ans[i].pos, ans[i].cnt);
	return 0;

}
int checkAns(void)
{
	int i, j, error=0;
	for (i=1; i < 5; i++)
	for (j=1; j < 5; j++)
	{
		if (map[i][j]!=(i-1)*4+j)
			error++;
	}
	return error;
}
void solve(int count)
{
	int sel, pos, cnt, i;
	int error = checkAns();
	if (!error)
	{
		if (min > count)
		{
			min = count;
			for (i=0; i < count; i++)
				ans[i] = p[i];
		}
		return;
	}
	if (count>=7)
		return;

	if (error > 4&&min-count<=2) return;
	if (error > 8&&min-count<=3) return;
	if (error > 12&&min-count<=4) return;
	if (count>=min-1) return;



	for (pos=1; pos < 5; pos++)
	for (cnt=1; cnt < 4; cnt++)
	for (sel=0; sel < 2; sel++)
	{
		if (count==0||!(p[count-1].sel==sel && p[count-1].pos==pos))
		{
			move(sel, pos, cnt);
			p[count].cnt = cnt; p[count].pos = pos; p[count].sel = sel;
			solve(count+1);
			move(sel, pos, 4-cnt);
		}
	}

}
int move(int sel, int pos, int cnt)
{
	int temp[5], i;

	if (sel==COL)
	{
		for (i=1; i < 5; i++)
			temp[i] = map[i][pos];

		for (i=1; i < 5; i++)
			map[i][pos] = temp[(i+3-cnt)%4+1];

	}

	if (sel==ROW)
	{
		for (i=1; i < 5; i++)
			temp[i] = map[pos][i];

		for (i=1; i < 5; i++)
			map[pos][i] = temp[(i+3-cnt)%4+1];
	}
}