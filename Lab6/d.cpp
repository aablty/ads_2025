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

int partition(Date arr[], int low, int high) {
    Date pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Date arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    
    quickSort(dates, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        printDate(dates[i]);
    }
    
    delete[] dates;
    return 0;
}