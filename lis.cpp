#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int C, N;
int arr[500];
int cache[500];
int logest(int k) {
	int& ret = cache[k];
	if (ret != -1) return ret;
	if (k == N - 1) return ret = 1;
	ret = 1;
	for (int i = k + 1; i < N; i++) {
		if (arr[k] < arr[i]) {
			ret = max(ret, logest(i) + 1);
		}
	}
	return ret;
}
int main() {
	scanf("%d", &C);
	while (C--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		int maxS = -1;
		for (int i = 0; i < N; i++) {
			memset(cache, -1, sizeof(cache));
			maxS = max(maxS, logest(i));
		}
		printf("%d\n", maxS);
	}

	return 0;
}