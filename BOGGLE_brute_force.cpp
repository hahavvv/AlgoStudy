#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
int C, n;
char board[5][5];
char temp[10][10];

int point[8][2] = {
	{-1,-1},{-1,0},{-1,1},
	{0,-1},{0,1},
	{1,-1},{1,0},{1,1} };
bool check(int y, int x, char* word,int k, int len) {
	if (k == len) return true;
	bool ok = false;
	for (int i = 0; i < 8; i++) {
		int ny = y + point[i][0];
		int nx = x + point[i][1];
		if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5) {
			if (board[ny][nx] == word[k]) {
				ok = true;
				if (check(ny, nx, word, k + 1, len))
					return ok;
				else
					ok = false;
			}
		}
	}
	return ok;
}
int main() {
	scanf("%d", &C);
	while(C--) {;
		for(int i=0;i<5;i++){
			scanf("%s", board[i]);
		}

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", temp[i]);
		}

		for (int i = 0; i < n; i++) {
			char tempC = temp[i][0];
			bool ok = false;
			for (int y = 0; y < 5; y++) {
				for (int x = 0; x < 5; x++) {
					if (tempC == board[y][x]) {
						if (check(y, x, temp[i],1, strlen(temp[i]))) {
							ok = true;
						}
					}
				}
			}
			if (ok) {
				printf("%s YES\n", temp[i]);
			}
			else printf("%s NO\n", temp[i]);
		}
	}
	return 0;
}