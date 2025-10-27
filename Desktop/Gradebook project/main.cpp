#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// struct and class are similar and both use the (./dot operator) in reference to the items defined in them
struct Student {

    string name;
    int id;
    vector<int> grades;

};

void addStudent(vector<Student>& students) {
 Student newStudent;

 cout << "Enter Student name: ";
 getline(cin, newStudent.name);

 cout << "Enter Student ID: ";
 cin >> newStudent.id;


 int numGrades;
 cout << "How many grades? \n";
 cin >> numGrades;


 for(int i= 0; i < numGrades; i++) {
    int grade;
    cout << "Enter grade " << i + 1 << ": ";
    cin >> grade;
    newStudent.grades.push_back(grade);
    
 }

 students.push_back(newStudent);



 cin.ignore();
}

void displayStudents(const vector<Student>& students) {
    if(students.empty()) {
        cout << "No students to display. \n";
        return;
    }

    for(const Student& s : students) {
        cout << "Name: " << s.name << "\n";
        cout << "ID: " << s.id << "\n";
        cout << "Grades: ";

        for(int grade : s.grades) {
            cout << grade << " ";
        }
        if(s.grades.empty()) {
            cout << "Average Grade: N/A (no grades entered)\n";
        } else {
            double sum = 0;
            for (int grade : s.grades) {
                sum += grade;
            }
            double average = sum / s.grades.size();
            cout << "Average Grade: " << fixed << setprecision(2) << average << "\n";
        }


        cout << "\n---------------------------\n";
    }

}



int main() {
vector<Student> students;
char choice;
do {
    addStudent(students);
    cout << "Add another student? (y/n): ";
    cin >> choice;
    cin.ignore(); // clear newline for next getline 

} while(choice == 'y' || choice == 'Y');

displayStudents(students);

    return 0;

}
