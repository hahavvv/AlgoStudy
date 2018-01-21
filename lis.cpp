#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int C, n;
int arr[500];
int cache[501];
int lis(int start) {
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = start + 1; i < n; i++) {
		if (start == -1 || arr[start] < arr[i]) {
			ret = max(ret, lis(i) + 1);
		}
	}
	return ret;
}
int main() {
	scanf("%d", &C);
	while (C--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		memset(cache, -1, sizeof(cache));
		printf("%d\n", lis(-1) - 1);
	}

	return 0;
}