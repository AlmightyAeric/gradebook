#pragma once
#include "roster.h"

// Default constructor
Roster::Roster() {}

// Parses a single student data entry, extracts its attributes, and adds the student to the roster
void Roster::parse(string studentData) {
    DegreeProgram degreeProgram = SECURITY; // Default to SECURITY if no program is specified
    // Determine the degree program based on the last character of the input data
    if (studentData.back() == 'K') degreeProgram = NETWORK;
    else if (studentData.back() == 'E') degreeProgram = SOFTWARE;

    // Parse the comma-separated student data
    int rhs = studentData.find(",");
    string StudentID = studentData.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string FirstName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string LastName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string EmailAddress = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int Age = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int Days1 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int Days2 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int Days3 = stoi(studentData.substr(lhs, rhs - lhs));

    // Add the student to the roster
    add(StudentID, FirstName, LastName, EmailAddress, Age, Days1, Days2, Days3, degreeProgram);
}

// Adds a new student to the roster
void Roster::add(string StudentID, string FirstName, string LastName, string Email, int Age, int Days1, int Days2, int Days3, DegreeProgram degreeProgram) {
    int Days[3] = { Days1, Days2, Days3 };
    // Increase LastIndex and add new student to the class roster
    classRosterArray[++LastIndex] = new Student(StudentID, FirstName, LastName, Email, Age, Days, degreeProgram);
}

// Prints all students in the roster
void Roster::printAll() {
    Student::printHeader();
    for (int i = 0; i <= LastIndex; i++) {
        // Format and display each student's data
        classRosterArray[i]->print();
    }
}

// Computes and displays the average number of days in the course for each student
void Roster::printAverageDaysInCourse(string StudentID) {
    for (int i = 0; i <= LastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == StudentID) {
            int average = (classRosterArray[i]->getDays()[0] +
                classRosterArray[i]->getDays()[1] +
                classRosterArray[i]->getDays()[2]) / 3;
            cout << "Student ID: " << StudentID << ", averages " << average << " days in a course." << endl;
        }
    }
}

// Identifies and prints invalid email addresses from the student roster
void Roster::printInvalidEmails() {
    bool any = false;
    for (int i = 0; i <= LastIndex; i++) {
        string EmailAddress = classRosterArray[i]->getEmailAddress();
        // Check for missing '@' or '.', or presence of spaces
        if (EmailAddress.find("@") == string::npos || EmailAddress.find('.') == string::npos || EmailAddress.find(' ') != string::npos) {
            any = true;
            cout << EmailAddress << ": Invalid" << endl;
        }
    }
    if (!any) cout << "NONE" << endl;
}

// Filters and prints students by their degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    Student::printHeader();
    for (int i = 0; i <= LastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

// Removes a student from the roster by their student ID
void Roster::remove(string StudentID) {
    bool found = false;
    for (int i = 0; i <= LastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == StudentID) {
            found = true;
            delete classRosterArray[i];
            for (int j = i; j < LastIndex; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            LastIndex--;
            cout << StudentID << " removed from the roster." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Student ID " << StudentID << " not found." << endl;
    }
}

// Destructor to clean up dynamically allocated student objects
Roster::~Roster() {
    for (int i = 0; i <= LastIndex; i++) {
        cout << "Destroying student #" << i + 1 << ": ";
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
    cout << "All students destroyed." << endl;
}