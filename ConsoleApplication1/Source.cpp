//Getting used to C++ and practice some sorting algs

#include <iostream>
#include <string>
using namespace std;

struct node {
	int x;
	node *next;
};

//String reversal
void reverseStr(char* str){
	reverse(str, str + strlen(str));
}


//quicksort
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++){
		if (arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high){
	if (low < high){
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

//heapsort
void buildMaxHeap(int arr[], int n, int i){
	int end = i;	//root
	int l = 2 * i + 1;	//left node
	int r = 2 * i + 2;	//right node

	if (l < n && arr[l] > arr[end]){
		end = l;
	}

	if (r < n && arr[r] > arr[end]){
		end = r;
	}

	if (end != i){
		swap(arr[i], arr[end]);

		buildMaxHeap(arr, n, end);
	}
}

void heapSort(int arr[], int n){
	for (int i = n / 2 - 1; i >= 0; i--){
		buildMaxHeap(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i++){
		swap(arr[0], arr[i]);

		buildMaxHeap(arr, i, 0);
	}
}

//test print out
void printArray(int arr[], int n){
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main()
{
	node *root;
	node *head;

	root = new node;
	root->next = 0;
	root->x = 12;
	head = root;

	if (head != 0) {
		while (head->next != 0){
			cout << head->x;
			head = head->next;
		}
		//cout << head->x;
	}
	head->next = new node;
	head = head->next;
	head->next = 0;
	head->x = 42;

	//tests
	//fizzbuzz();

	int arrTest[] = { 11, 10, 9, 21, 6, 7, 9 };
	int n = sizeof(arrTest) / sizeof(arrTest[0]);

	//quickSort(arrTest, 0, n);
	heapSort(arrTest, n);
	printArray(arrTest, n);

	char test[16] = "Hello world";
	reverseStr(test);
	cout << test;
}



/*B[i] is the product of all A[j] where j != i.
A = { 2, 1, 5, 9 }, then B would be{ 45, 90, 18, 10 }

void F(int* A, int* B, int N)*/