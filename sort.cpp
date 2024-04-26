#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <chrono>
using namespace std;


//Insertion Sort
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//merge 
void merge_sort(int arr[], int l, int r) {
    if (l >= r)
        return;
    int m = (l + r - 1) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//Quicksort
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

//Quick-insertion
void quick_insertion_sort(int arr[], int low, int high, int k) {
    if (low < high) {
        if (high - low + 1 < k) {
            insertion_sort(arr + low, high - low + 1);
        }
        else {
            int pi = partition(arr, low, high);
            quick_insertion_sort(arr, low, pi - 1, k);
            quick_insertion_sort(arr, pi + 1, high, k);
        }
    }
}

int randomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    double time;
    std::chrono::duration<double> elapsed_seconds;

    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    int arr1[n], arr2[n], temp[n];

    for (int i = 0; i < n; i++) {
        arr1[i] = randomNumber(1, 1000);
        arr2[i] = arr1[i];
    }

    cout << "Unsorted Array\n";
    print_array(arr1, n);
    cout << "\nSorting using insertion sort\n";
    start = std::chrono::system_clock::now();
    insertion_sort(arr2, n - 1);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    time = elapsed_seconds.count();
    cout << "Sorted Array\n";
    print_array(arr2, n);
    cout << "\nElapse Time : " << time << "\n\n";

    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[i];
    }

    cout << "\n\nUnsorted Array\n";
    print_array(arr1, n);
    cout << "\nSorting using merge sort\n";
    start = std::chrono::system_clock::now();
    merge_sort(arr2, temp, 0, n - 1);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    time = elapsed_seconds.count();
    cout << "Sorted Array\n";
    print_array(arr2, n);
    cout << "\nElapse Time : " << time << "\n\n";

    for (int i = 0; i < n; i++)arr2[i] = arr1[i];
    cout << "\n\nUnsorted Array\n";
    print_array(arr1, n);
    cout << "\nSorting using quick sort\n";
    start = std::chrono::system_clock::now();
    quick_sort(arr2, 0, n - 1);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    time = elapsed_seconds.count();
    cout << "Sorted Array\n";
    print_array(arr2, n);
    cout << "\nElapse Time : " << time << "\n\n";

    for (int i = 0; i < n; i++)arr2[i] = arr1[i];
    cout << "\n\nUnsorted Array\n";
    print_array(arr1, n);
    cout << "\nSorting using quick-insertion sort\n";
    start = std::chrono::system_clock::now();
    quick_insertion_sort(arr2, 0, n - 1, k);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    time = elapsed_seconds.count();
    cout << "Sorted Array\n";
    print_array(arr2, n);
    cout << "\nElapse Time : " << time << "\n\n";


    return 0;
}
