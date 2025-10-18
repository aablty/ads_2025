#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Change {
    string original;
    string final;
};

int partition(Change arr[], int low, int high) {
    string pivot = arr[high].original;
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j].original < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Change arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    
    map<string, string> forward;  
    map<string, string> backward; 
    
    for (int i = 0; i < n; i++) {
        string oldNick, newNick;
        cin >> oldNick >> newNick;
        
        string original = oldNick;
        if (backward.find(oldNick) != backward.end()) {
            original = backward[oldNick];
            backward.erase(oldNick);
        }
        
        forward[original] = newNick;
        backward[newNick] = original;
    }
    
    int count = forward.size();
    Change* changes = new Change[count];
    int idx = 0;
    
    for (auto& p : forward) {
        changes[idx].original = p.first;
        changes[idx].final = p.second;
        idx++;
    }
    
    quickSort(changes, 0, count - 1);
    
    cout << count << endl;
    for (int i = 0; i < count; i++) {
        cout << changes[i].original << " " << changes[i].final << endl;
    }
    
    delete[] changes;
    return 0;
}