#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    string lastname;
    string firstname;
    double gpa;
};

double getGradeValue(string grade) {
    if (grade == "A+") return 4.00;
    if (grade == "A") return 3.75;
    if (grade == "B+") return 3.50;
    if (grade == "B") return 3.00;
    if (grade == "C+") return 2.50;
    if (grade == "C") return 2.00;
    if (grade == "D+") return 1.50;
    if (grade == "D") return 1.00;
    if (grade == "F") return 0.00;
    return 0.00;
}

bool compare(Student& a, Student& b) {
    if (a.gpa != b.gpa) {
        return a.gpa < b.gpa;
    }
    if (a.lastname != b.lastname) {
        return a.lastname < b.lastname;
    }
    return a.firstname < b.firstname;
}

int partition(Student arr[], int low, int high) {
    Student pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    
    Student* students = new Student[n];
    
    for (int i = 0; i < n; i++) {
        cin >> students[i].lastname >> students[i].firstname;
        
        int m;
        cin >> m;
        
        double totalPoints = 0;
        int totalCredits = 0;
        
        for (int j = 0; j < m; j++) {
            string grade;
            int credits;
            cin >> grade >> credits;
            
            totalPoints += getGradeValue(grade) * credits;
            totalCredits += credits;
        }
        
        students[i].gpa = totalPoints / totalCredits;
    }
    
    quickSort(students, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << students[i].lastname << " " << students[i].firstname << " ";
        cout << fixed << setprecision(3) << students[i].gpa << endl;
    }
    
    delete[] students;
    
    return 0;
}