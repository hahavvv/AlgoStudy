#include <iostream>
#include <string.h>
using namespace std;
int C, n;
int cache[101];
int bino(int i) {
	if (i == 1 || i == 2) return cache[i];
	int &ret = cache[i];
	if (ret != -1) return ret;
	return ret = (bino(i - 1) + bino(i - 2)) % 1000000007;
}
int main() {

	scanf("%d", &C);
	while (C--) {
		memset(cache, -1, sizeof(cache));
		cache[1] = 1;
		cache[2] = 2;
		scanf("%d", &n);
		printf("%d\n", bino(n));
	}
	return 0;
}