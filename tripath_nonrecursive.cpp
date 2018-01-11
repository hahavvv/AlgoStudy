#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int C, n;
int board[100][100];
int cache[100][100];
int main() {
	scanf("%d", &C);
	for (int i = 0; i < C; i++) {
		scanf("%d", &n);
		memset(cache, -1, sizeof(cache));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < j+1; k++) {
				scanf("%d", &board[j][k]);
			}
		}

		for (int j = 0; j < n-1; j++) {
			for (int k = 0; k < j+1;k++) {
				int temp;
				if (cache[j][k] != -1) {
					temp = cache[j][k];
				}
				else { temp = board[j][k]; }
				int tempA = temp + board[j + 1][k];
				int tempB = temp + board[j + 1][k + 1];
				if (cache[j + 1][k] < tempA) {
					cache[j + 1][k] = tempA;
				}
				if (cache[j + 1][k + 1] < tempB) {
					cache[j + 1][k + 1] = tempB;
				}
			}
		}

		int max = -1;
		for (int i = 0; i < n; i++) {
			if (cache[n - 1][i] > max) {
				max = cache[n - 1][i];
			}
		}
		printf("%d\n", max);
	}
	return 0;
}