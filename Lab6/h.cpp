#include <iostream>
using namespace std;

int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    
    char* arr = new char[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    char letter;
    cin >> letter;
    
    quickSort(arr, 0, n - 1);
    
    char balanced = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > letter) {
            balanced = arr[i];
            break;
        }
    }
    
    cout << balanced << endl;
    
    delete[] arr;
    return 0;
}