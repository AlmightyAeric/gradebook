#pragma once
#include "student.h"

// Default constructor initializes members to default values
Student::Student() {
    this->StudentID = "";  // Initialize to empty string, safer than using NULL
    this->FirstName = "";
    this->LastName = "";
    this->EmailAddress = "";
    this->Age = 0;
    for (int i = 0; i < DaysInCourse; i++) {
        this->Days[i] = 0;  // Initialize days array to zero
    }
    this->degreeProgram = DegreeProgram::SECURITY; // Default degree program
}

// Parametrized constructor initializes members with given values
Student::Student(string StudentId, string FirstName, string LastName, string EmailAddress, int Age, int Days[], DegreeProgram degreeProgram) {
    this->StudentID = StudentId;
    this->FirstName = FirstName;
    this->LastName = LastName;
    this->EmailAddress = EmailAddress;
    this->Age = Age;
    for (int i = 0; i < DaysInCourse; i++) {
        this->Days[i] = Days[i];  // Copy days array
    }
    this->degreeProgram = degreeProgram;
}

// Destructor: Currently does nothing since no dynamic memory is used
Student::~Student() {}

// Accessor methods return the values of member variables
string Student::getStudentID() { return this->StudentID; }
string Student::getFirstName() { return this->FirstName; }
string Student::getLastName() { return this->LastName; }
string Student::getEmailAddress() { return this->EmailAddress; }
int Student::getAge() { return this->Age; }
int* Student::getDays() { return this->Days; }  // Returns pointer to Days array
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

// Mutator methods set the values of member variables
void Student::setStudentID(string StudentID) { this->StudentID = StudentID; }
void Student::setFirstName(string FirstName) { this->FirstName = FirstName; }
void Student::setLastName(string LastName) { this->LastName = LastName; }
void Student::setEmailAddress(string EmailAddress) { this->EmailAddress = EmailAddress; }
void Student::setAge(int Age) { this->Age = Age; }
void Student::setDays(int Days[]) {
    for (int i = 0; i < DaysInCourse; i++) {
        this->Days[i] = Days[i];  // Copy days array
    }
}
void Student::setDegreeProgram(DegreeProgram degreeprogram) { this->degreeProgram = degreeprogram; }

// Prints a header to describe the output format of student data
void Student::printHeader() {
    cout << "Output format: StudentID|FirstName|LastName|Email|Age|DaysInCourse|DegreeProgram\n";
}

// Prints the student's data in a formatted manner
void Student::print() {
    cout << this->getStudentID() << '\t'; // Tab-separated values
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmailAddress() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDays()[0] << ','; // Comma-separated days
    cout << this->getDays()[1] << ',';
    cout << this->getDays()[2] << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << '\n'; // Print degree program as string
};