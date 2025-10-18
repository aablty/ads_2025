#include <iostream>
using namespace std;

struct Date {
    int day, month, year;
    
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

void parseDate(const char* str, Date& date) {
    date.day = (str[0] - '0') * 10 + (str[1] - '0');
    date.month = (str[3] - '0') * 10 + (str[4] - '0');
    date.year = (str[6] - '0') * 1000 + (str[7] - '0') * 100 + 
                (str[8] - '0') * 10 + (str[9] - '0');
}

void printDate(const Date& date) {
    if (date.day < 10) cout << '0';
    cout << date.day << '-';
    if (date.month < 10) cout << '0';
    cout << date.month << '-';
    cout << date.year << '\n';
}

void swap(Date& a, Date& b) {
    Date temp = a;
    a = b;
    b = temp;
}

void heapify(Date arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[largest] < arr[left])
        largest = left;
    
    if (right < n && arr[largest] < arr[right])
        largest = right;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(Date arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    
    Date* dates = new Date[n];
    char buffer[11];
    
    for (int i = 0; i < n; i++) {
        cin >> buffer;
        parseDate(buffer, dates[i]);
    }
    
    heapSort(dates, n);
    
    for (int i = 0; i < n; i++) {
        printDate(dates[i]);
    }
    
    delete[] dates;
    return 0;
}