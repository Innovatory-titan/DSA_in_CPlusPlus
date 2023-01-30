#include <bits/stdc++.h>
using namespace std;

/* all sorting algorithms that I am gonna use in this session are :- Bubble Sort, Insertion Sort, Selection Sort, Merge Sort, Heap Sort
Merge Sort is best of all while using in big data in terms of time complexibility and stability ...*/

/* void bubbleSort(int arr[], int n){
	// let's learn about bubble sort today
	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < n-i-1; j++)
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
} */

/* void selectionSort(int arr[], int size){
	int i, j, min_idx;
	for (i = 0; i < size-1; i++){
		min_idx = i;
		for (j = i+1; j < size; j++)
			if (arr[j] < arr[min_idx]) min_idx = j;
		swap(arr[i], arr[min_idx]);
	}
} */

/* void insertionSort(int arr[], int n){
	int i, j, key;
	for (i = 1; i < n; i++){
		key = arr[i];
		j = i-1;
		while (j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j -= 1;
		}
		arr[j+1] = key;
	}
} */

int main(){
	int array[] = {9, 11, 2, 10, 5};
	int size = sizeof(array)/sizeof(array[0]);
	// bubbleSort(array, size);
    // selectionSort(array, size);
    // insertionSort(array, size);
	for (auto x : array){
		cout << x << " ";
	}
}
