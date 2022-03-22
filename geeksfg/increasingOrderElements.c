#include <stdio.h>

// int m = 10;

int maximum_sum(int n, int m, int a [n][m] ) {
	// int** a = (int**) b;
	int maxCum, sumCum, maxEl;
	maxEl = a[n-1][0];
	for (int j = 0; j < m; j++) {
		if (a[n-1][j] > maxEl) {
			maxEl = a[n-1][j];
		}
	}
	sumCum = maxEl;
	maxCum = maxEl;
	for (int i = n-2; i >= 0; i--) { 
		maxEl = a[i][0];
		int flag = 0;
		for (int j = 0; j < m; j++) {
			if (maxEl > a[i][j])
				maxEl = a[i][j];
		}

		for (int j = 0; j < m; j++) {
			if (a[i][j] >= maxEl && a[i][j] < maxCum) {
				maxEl = a[i][j];
				flag = 1;
			}
		}
		if (flag == 0)
			return 0;
		maxCum = maxEl;
		sumCum += maxEl;
	}
	return sumCum;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		printf("%d ", a[i][j]);
	//	}
	//	printf("\n");
	//}
	int cumSum = maximum_sum(n, m, a);
	printf("%d", cumSum); 
	return 0;
}


