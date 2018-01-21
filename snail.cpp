#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int C, n, m;
float cache[1001][1003];
float result(int day, int meter) {
	if (day == m) return meter >= n;
	float &ret = cache[day][meter];
	if (ret != -1) return ret;
	return ret = 0.75*result(day + 1, meter + 2) + 0.25*result(day + 1, meter + 1);
}
int main() {
	scanf("%d", &C);
	while (C--) {		
		scanf("%d %d", &n, &m);
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1003; j++) {
				cache[i][j] = -1.0f;
			}
		}
		printf("%.10f", result(0, 0));
	}

	return 0;
}