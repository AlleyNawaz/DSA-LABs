#include <iostream>
using namespace std;

// Quick Sort (Descending)
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] > pivot){ // descending
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    int arr[] = {45, 20, 60, 10, 75, 30};
    int n = 6;

    cout << "Original: ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";

    quickSort(arr, 0, n-1);

    cout << "\nSorted (Descending): ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";

    return 0;
}