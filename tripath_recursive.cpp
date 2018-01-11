#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int C, n;
int board[100][100];
int cache[100][100];
int recursPath(int y, int x) {
	if (y == n - 1) return board[y][x];
	int& ret = cache[y][x];
	if (cache[y][x] != -1) return ret;
	return ret = board[y][x] + max(recursPath(y + 1, x), recursPath(y + 1, x + 1));
}
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
		printf("%d\n", recursPath(0,0));
	}
	return 0;
}