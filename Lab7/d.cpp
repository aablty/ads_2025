#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student
{
    string lastname;
    string firstname;
    double gpa;
};

double getGradeValue(string grade)
{
    if (grade == "A+")
        return 4.00;
    if (grade == "A")
        return 3.75;
    if (grade == "B+")
        return 3.50;
    if (grade == "B")
        return 3.00;
    if (grade == "C+")
        return 2.50;
    if (grade == "C")
        return 2.00;
    if (grade == "D+")
        return 1.50;
    if (grade == "D")
        return 1.00;
    if (grade == "F")
        return 0.00;
    return 0.00;
}

bool compare(Student &a, Student &b)
{
    if (a.gpa != b.gpa)
    {
        return a.gpa < b.gpa;
    }
    if (a.lastname != b.lastname)
    {
        return a.lastname < b.lastname;
    }
    return a.firstname < b.firstname;
}

void merge(Student arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Student *L = new Student[n1];
    Student *R = new Student[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (compare(L[i], R[j]))
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void merge_sort(Student arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n;

    Student *students = new Student[n];

    for (int i = 0; i < n; i++)
    {
        cin >> students[i].lastname >> students[i].firstname;

        int m;
        cin >> m;

        double totalPoints = 0;
        int totalCredits = 0;

        for (int j = 0; j < m; j++)
        {
            string grade;
            int credits;
            cin >> grade >> credits;

            totalPoints += getGradeValue(grade) * credits;
            totalCredits += credits;
        }

        students[i].gpa = totalPoints / totalCredits;
    }

    merge_sort(students, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << students[i].lastname << " " << students[i].firstname << " ";
        cout << fixed << setprecision(3) << students[i].gpa << endl;
    }

    delete[] students;

    return 0;
}