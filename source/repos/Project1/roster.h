#pragma once
#include "student.h"  // Include the Student class header

class Roster
{
public:
    // Maximum number of students in the roster
    const static int numStudents = 5;

    // Array of pointers to Student objects, representing the class roster
    Student* classRosterArray[numStudents];

    // Index of the last student added to the roster, initialized to -1 indicating empty
    int LastIndex = -1;

public:
    Roster();  // Constructor declaration
    ~Roster(); // Destructor declaration

    // Parses a string to extract student data and add a new student to the roster
    void parse(string row);

    // Adds a new student to the roster with detailed information
    void add(string StudentID, string FirstName, string LastName, string Email, int Age, int Days1, int Days2, int Days3, DegreeProgram degreeprogram);

    // Prints information of all students in the roster
    void printAll();

    // Calculates and prints the average number of days in the course for a student by their ID
    void printAverageDaysInCourse(string StudentID);

    // Prints all email addresses that do not follow standard formats
    void printInvalidEmails();

    // Prints the details of students by their degree program
    void printByDegreeProgram(DegreeProgram degreeprogram);

    // Removes a student from the roster by their Student ID
    void remove(string StudentID);
};
