#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int C, n;
int cache[100][100];
int countCache[100][100];
int arr[100][100];
int result(int y, int x) {
	if (y == n - 1) return arr[y][x];
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	return ret = arr[y][x] + max(result(y + 1, x), result(y + 1, x + 1));
}
int countPath(int y, int x) {
	if (y == n - 1) return 1;
	int &ret = countCache[y][x];
	if (ret != -1) return ret;
	ret = 0;
	int tempA = result(y + 1, x);
	int tempB = result(y + 1, x + 1);
	if (tempA >= tempB) ret += countPath(y + 1, x);
	if (tempA <= tempB) ret += countPath(y + 1, x + 1);
	return ret;
}
int main() {
	scanf("%d", &C);
	while (C--) {
		memset(cache, -1, sizeof(cache));
		memset(countCache, -1, sizeof(countCache));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		printf("%d\n", countPath(0, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				cout << countCache[i][j]<<" ";
			}
			cout << endl;
		}
	}
}