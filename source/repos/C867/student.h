#pragma once
#include <string>
#include <iostream>
#include "degree.h" // Include the header for the DegreeProgram enumeration

using namespace std;

class Student
{
public:
    // Constant to represent the number of courses (used in the Days array)
    const static int DaysInCourse = 3;

private:
    // Private member variables to store student details
    string StudentID;
    string FirstName;
    string LastName;
    string EmailAddress;
    int Age;
    int Days[DaysInCourse];  // Array to store the number of days in course
    DegreeProgram degreeProgram;  // Enumeration for degree program

public:
    Student(); // Default constructor
    // Constructor to initialize all member variables
    Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int Days[], DegreeProgram degreeProgram);
    ~Student(); // Destructor

    // Getters or accessors for each member variable
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDays(); // Returns a pointer to the Days array
    DegreeProgram getDegreeProgram();

    // Setters or mutators for each member variable
    void setStudentID(string StudentID);
    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setEmailAddress(string EmailAddress);
    void setAge(int Age);
    void setDays(int Days[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    static void printHeader(); // Static function to print the header for displaying student data
    void print(); // Prints the student's data
};
#pragma once
