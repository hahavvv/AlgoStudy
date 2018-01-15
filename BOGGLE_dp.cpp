#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
int C, n;
char board[6][6];
char temp[11];
int cache[11][6][6];
int dydx[8][2] = {
	{-1,0},{1,0},
	{0,-1},{0,1},
	{-1,-1},{-1,1},
	{1,-1},{1,1}
};
int check(int y, int x, char* word, int id) {
	int &ret = cache[id][y][x];
	if (ret != -1) return ret;
	for (int i = 0; i < 8; i++) {
		int ny = y + dydx[i][0];
		int nx = x + dydx[i][1];
		if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5) {
			if (board[ny][nx] == word[id]) {
				if (word[id + 1] == '\0') return ret = 1;
				ret = check(ny, nx, word, id + 1);
				if (ret == 1) return ret;
			}
			
		}
	}
	return ret = 0;
}
int find() {
	memset(cache, -1, sizeof(cache));
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			int& ret = cache[0][y][x];
			if (ret != -1) return ret;
			if (board[y][x] == temp[0]) {
				ret = check(y, x, temp, 1);
				if (ret == 1) return ret;
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d", &C);
	while (C--) {
		for (int i = 0; i<5; i++) {
			scanf("%s", board[i]);
		}

		scanf("%d", &n);
		while (n--) {
			scanf("%s", temp);
			printf("%s %s\n", temp, find() ? "YES" : "NO");;
		}
	}
	return 0;
}