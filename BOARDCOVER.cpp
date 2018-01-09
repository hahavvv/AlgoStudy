#include <iostream>
#include <string>
#include <vector>
using namespace std;
int C, H, W;
string temp;
vector<vector<int>> board;
int shapetype[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};
bool set(int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		int ny = y + shapetype[type][i][0];
		int nx = x + shapetype[type][i][1];
		if (ny < 0 || ny >= board.size() ||
			nx < 0 || nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}
int check() {
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)
			break;
	}
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (set(y, x, type, 1)) {
			ret += check();
		}
		set(y, x, type, -1);
	}
	return ret;
}
int main() {
	scanf("%d", &C);
	for (int i = 0; i < C; i++) {
		scanf("%d %d", &H, &W);
		for (int j = 0; j < H; j++) {
			vector<int> e(W);
			board.push_back(e);
			cin >> temp;
			for (int k = 0; k < W; k++) {
				if (temp[k] == '#') board[j][k] = 1;
				else board[j][k] = 0;
			}
		}
		printf("%d\n", check());

		for (int j = 0; j < H; j++) {
			board[j].clear();
		}
		board.clear();
	}
	return 0;
}