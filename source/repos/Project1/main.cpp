#pragma once
#include "roster.h"
#include "student.h"

int main()
{
    cout << "Course : Scripting and Programming Application C867" << std::endl;
    cout << "Language used: C++" << std::endl;
    cout << "011286265" << std::endl;
    cout << "Eric Davis" << std::endl;
    cout << "\n";

    // Array of strings representing student data
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Eric,Davis,edav640@wgu.edu,23,30,40,30,SOFTWARE"
    };

    const int numStudents = 5; // Number of students in the array
    Roster classRoster; // Creating an instance of Roster

    // Parsing student data and adding students to the roster
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);

    // Printing all students in the roster
    cout << "Class Roster: " << std::endl;
    classRoster.printAll();
    cout << std::endl;

    // Displaying invalid email addresses
    cout << "Displaying invalid Emails:" << std::endl;
    cout << "\n";
    classRoster.printInvalidEmails();
    cout << std::endl;

    // Calculating and displaying average days in course for each student
    cout << "Average days in course for each student is: " << std::endl;
    cout << "\n";
    for (int i = 0; i < numStudents; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }

    // Displaying students by the degree program: SOFTWARE
    cout << "\n";
    cout << "Displaying by degree program: " << degreeProgramStrings[2] << std::endl;
    cout << "\n";
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;

    // Removing a student and attempting to remove them again to demonstrate error handling
    cout << "Removing Student A3" << std::endl;
    classRoster.remove("A3");
    classRoster.printAll();
    cout << std::endl;

    cout << "Removing Student A3 again" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    system("pause"); // Pause the system before exiting to view output
    return 0;
}