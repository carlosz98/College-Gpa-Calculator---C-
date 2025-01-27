#include <iostream>
#include <vector>
#include <iomanip>
#include <limits> 
#include <string>

using namespace std;

struct Course {
    string name;
    int credits;
    double grade;
};

double calculateGPA(const vector<Course>& courses) {
    if (courses.empty()) {
        return 0.0;
    }

    double totalGradePoints = 0;
    int totalCredits = 0;

    for (const auto& course : courses) {
        totalGradePoints += course.grade * course.credits;
        totalCredits += course.credits;
    }

    return totalGradePoints / totalCredits;
}

int main() {
    vector<Course> courses;
    int numCourses;

    cout << "Enter the number of courses: ";
    cin >> numCourses;


    while (cin.fail() || numCourses <= 0) {
        cout << "Invalid input. Please enter a positive integer for the number of courses: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> numCourses;
    }

    for (int i = 0; i < numCourses; ++i) {
        Course course;
        cout << "\nEnter details for course " << i + 1 << ":" << endl;

        cout << "Course Name: ";
        cin.ignore();
        getline(cin, course.name);

        cout << "Credits: ";
        cin >> course.credits;

        while (cin.fail() || course.credits <= 0) {
            cout << "Invalid input. Please enter a positive integer for credits: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> course.credits;
        }

        cout << "Grade (e.g., 4.0, 3.7, 3.0, etc.): ";
        cin >> course.grade;

        while (cin.fail() || course.grade < 0.0 || course.grade > 4.0) {
            cout << "Invalid input. Please enter a grade between 0.0 and 4.0: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> course.grade;
        }

        courses.push_back(course);
    }

    double gpa = calculateGPA(courses);

    cout << fixed << setprecision(2);
    cout << "\nYour CGPA is: " << gpa << endl;

    return 0;
}