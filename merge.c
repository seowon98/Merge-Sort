#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int a[5] = { 3,9,6,10,8 };
int sorted[5];

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle;
	int k=m;

	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}

	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t < middle; t++) {
			sorted[k] = a[t];
			k++;
		}
		}
	for (int t=0; t <= n; t++) a[t] = sorted[t];
	}

void mergeSort(int a[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m,middle, n);
	}
}

int main() {
	
	for(int i=0; i<5;i++) printf("%d ", a[i]);

	mergeSort(a, 0, 4);

	for (int i = 0; i<5; i++) printf("%d ", sorted[i]);

}



