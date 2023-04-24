#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {
    std::cout << "C867 Scripting & Programing: Applications" << endl;
    std::cout << "Language: C++" << endl;
    std::cout << "Name: Jennifer Cole" << endl;
    std::cout << "Student ID: #001265274" << endl;
    std::cout << endl;

    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jenn,Cole ,jcol627@wgu.edu,32,30,24,18,SOFTWARE" };

    Roster classRoster;
    Student s;

    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    }
   
    std::cout << "Displaying all students: " << endl;
    classRoster.printAll();
    std::cout << endl;

    std::cout << "Displaying invalid emails: " << endl;
    classRoster.printInvalidEmails();
    std::cout << endl;
    
    for (int i = 0; i < 5; i++) {
        Student* studentPointer = classRoster.getClassRosterArray(i);
        string studentID = studentPointer->getStudentID();
        classRoster.printAverageDaysInCourse(studentID);
    }
    std::cout << endl;

    std::cout << "Displaying students in Degree Program SOTWARE: " << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    std::cout << endl;

    std::cout << "Removing A3:" << endl;
    classRoster.remove("A3");
    std::cout << endl;

    std::cout << "Displaying all students: " << endl;
    classRoster.printAll();
    std::cout << endl;

    std::cout << "Removing A3 again:" << endl;
    classRoster.remove("A3");
    std::cout << endl;

    return 0;
}