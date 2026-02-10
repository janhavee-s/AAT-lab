//binary search
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high)/2;

        if (arr[mid] == key)
            return mid;       
        else if (arr[mid] < key)
            low = mid + 1;    
        else
            high = mid - 1;  
    }
    return -1; 
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56};
    int n = 8;
    int key = 23;
    int result = binarySearch(arr, n, key);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}


//merge sort
#include <iostream>
using namespace std;

void merge(int A[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[20];
    while (i <= mid && j <= high) {
        if (A[i] <= A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= mid)
        temp[k++] = A[i++];
    while (j <= high)
        temp[k++] = A[j++];
    for (i = 0; i < k; i++)
        A[low + i] = temp[i];
}
void mergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;   
        mergeSort(A, low, mid);       
        mergeSort(A, mid + 1, high);  
        merge(A, low, mid, high);     
    }
}

int main() {
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;
    mergeSort(A, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}


//quick sort
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int P = low + 1;
    int Q = high;
    while (P <= Q) {
        while (P <= high && arr[P] <= pivot)
            P++;
        while (arr[Q] > pivot)
            Q--;

        if (P < Q)
            swap(arr[P], arr[Q]);
    }
    swap(arr[low], arr[Q]);
    return Q;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array (Quick Sort): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
