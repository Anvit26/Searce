#include <iostream>
using namespace std;

void displayArr(int* a,const  int& s) {
	for (int i = 0; i < s; i++) {
		cout << a[i] << " ";
	}
	cout<<endl;
}


void selectionSort(int* a,const int& s) {
	for (int i = 0; i < s; i++) {
		int min = i;
		for (int j = i + 1; j < s; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		if (min != i) {
			int tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
		}
	}
}

void insertionSort(int* a, const int& s) {
	
		for (int i = 1; i < s; i++) {
			int tmp = a[i];
			int j = i;
			while (j > 0 && a[j-1] >= tmp) {
				a[j] = a[j-1];
				j--;
			}
			a[j] = tmp;
		}
}

void merge(int arr[], int l, int m, int r) {
	int i = l;
	int j = m + 1;
	int k = l;

	/* create temp array */
	int temp[r];

	while (i <= m && j <= r) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		}
		else {
			temp[k] = arr[j];
			j++;
			k++;
		}

	}

	/* Copy the remaining elements of first half, if there are any */
	while (i <= m) {
		temp[k] = arr[i];
		i++;
		k++;

	}

	/* Copy the remaining elements of second half, if there are any */
	while (j <= r) {
		temp[k] = arr[j];
		j++;
		k++;
	}

	/* Copy the temp array to original array */
	for (int p = l; p <= r; p++) {
		arr[p] = temp[p];
	}
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		// find midpoint
		int m = (l + r) / 2;

		// recurcive mergesort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		// merge
		merge(arr, l, m, r);
	}
}

int main() {
	const int size = 7;
	
	int arr1[size] = { 6,2,8,1,9,8,5 };
	displayArr(arr1, size);
	
	cout << "selection sort: " << endl;
	selectionSort(arr1, size);
	displayArr(arr1, size);

    int arr2[size] = { 16,12,18,11,19,18,15 };
	cout << "insertion sort: " << endl;
	insertionSort(arr2, size);
	displayArr(arr2, size);

    int arr3[size] = { 26,22,28,21,29,28,25 };
	cout << "merge sort: " << endl;
	mergeSort(arr3, 0,size-1);
	displayArr(arr3, size);
	return 0;
}
