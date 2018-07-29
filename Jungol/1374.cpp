#include <stdio.h>

#define MAX_S	200

char str1[MAX_S + 5], str2[MAX_S + 5];
int ret_add[MAX_S + 5], ret_sub[MAX_S + 5];
int len1, len2;

int strlen(char *str) {
	int ret = 0;
	while (*str != NULL) {
		ret++;
		str++;
	}
	return ret;
}

void strcpy(char *des, char *sou) {
	while (*sou != NULL) {
		*des++ = *sou++;
	}
	*des = NULL;
}

void swap(char *s1, char *s2) {
	char temp[MAX_S + 5];
	strcpy(temp, s1);
	strcpy(s1, s2);
	strcpy(s2, temp);
}

void swap(int *s1, int *s2) {
	int temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void StrToInt(int *n1, int *n2) {
	for (int i = 0; i < len1; ++i) {
		n1[MAX_S - i] = str1[len1 - i - 1] - '0';
	}

	for (int i = 0; i < len2; ++i) {
		n2[MAX_S - i] = str2[len2 - i - 1] - '0';
	}
}

void add(int * n1, int * n2) {
	for (int i = MAX_S; i > MAX_S - len1; i--) {
		ret_add[i] += n1[i] + n2[i];
		ret_add[i - 1] = ret_add[i] / 10;
		ret_add[i] %= 10;
	}
}

void sub(int * n1, int * n2) {
	for (int i = MAX_S; i > MAX_S - len1; i--) {
		ret_sub[i] += n1[i] - n2[i];
		if (ret_sub[i] < 0) {
			ret_sub[i - 1]--;
			ret_sub[i] += 10;
		}
	}
}

void init(void) {
	for (int i = 0; i < MAX_S + 5; ++i) {
		ret_add[i] = 0;
		ret_sub[i] = 0;
	}
}

int main(void) {
	str1[0] = 'a';
	
	while (true) {
		init();

		scanf("%s", str1);
		getchar();
		scanf("%s", str2);
		getchar();

		if (str1[0] == '0' && str2[0] == '0')
			break;

		len1 = strlen(str1);
		len2 = strlen(str2);

		if (len1 <= len2) {
			if (!(len1 == len2 && str1[0] > str2[0])) {
				swap(str1, str2);
				swap(&len1, &len2);
			}
		}

		int num1[MAX_S + 5] = { 0, };
		int num2[MAX_S + 5] = { 0, };

		StrToInt(num1, num2);

		add(num1, num2);
		sub(num1, num2);
		
		int i = 0;
		while (ret_add[i] == 0 && i < MAX_S) i++;
		for (; i <= MAX_S; ++i) {
			printf("%d", ret_add[i]);
		}
		printf("\n");

		i = 0;
		while (ret_sub[i] == 0 && i < MAX_S) i++;
		for (; i <= MAX_S; ++i) {
		
			printf("%d", ret_sub[i]);
		}
		printf("\n");
	}

	return 0;
}