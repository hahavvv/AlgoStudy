#include <iostream>
#include <string.h>
using namespace std;
int T, n, m, a, b;
bool Pairs[10][10];
bool Pairing[10];
int check() {
	int first = -1;
	for (int i = 0; i < n; i++) {
		if (!Pairing[i]) {
			first = i;
			break;
		}
	}
	if (first == -1) return 1;
	int ret = 0;
	for (int p = first + 1; p < n; p++) {
		if (!Pairing[p] && Pairs[p][first]) {
			Pairing[p] = Pairing[first] = true;
			ret += check();
			Pairing[p] = Pairing[first] = false;
		}
	}
	return ret;
}
int main() {
	int *result;
	scanf("%d", &T);
	result = new int[T];
	for (int i = 0; i < T; i++) {
		for (int k = 0; k < 10; k++) {
			memset(Pairs[k], false, sizeof(bool) *10);
		}
		memset(Pairing, false, sizeof(bool) * 10);
		scanf("%d %d", &n, &m);
		for (int k = 0; k < m; k++) {
			scanf("%d %d", &a, &b);
			Pairs[a][b] = Pairs[b][a] = true;
		}
		result[i] = check();
	}
	for (int i = 0; i < T; i++) {
		printf("%d\n", result[i]);
	}
}