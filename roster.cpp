#include <iostream>
#include <string>
#include <regex>
#include "roster.h"
using namespace std;

Student* classRosterArray = new Student[5];
int n = 0;

Roster::Roster() {
	
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysToComplete1, int daysToComplete2, int daysToComplete3, enum DegreeProgram degree) {

	Student* s = new Student(studentID, firstName, lastName, emailAddress, age,
		daysToComplete1, daysToComplete2, daysToComplete3, degree);
	classRosterArray[n] = s;
	n++;
}

void Roster::remove(string studentID) {
	int i = 0;
	int studentIndex = -1;
	while (i < 5) {
		Student s = *classRosterArray[i];
		if (s.getStudentID() == studentID) {
			studentIndex = i;
			*classRosterArray[i] = Student();
		}
		i++;
	}
	if (studentIndex == -1) {
		std::cout << "Such a student with ID: " << studentID << " was not found.";
	}
}

void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		Student s = *classRosterArray[i];
		if (s.getStudentID() != "") {
			s.print(*classRosterArray[i]);
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int i = 0;
	int* daysArray;
	int days = 0;
	while (i < 5) {
		Student s = *classRosterArray[i];
		if (s.getStudentID() == studentID) {
			daysArray = s.getDaysToComplete();
			break;
		}
		else {
			daysArray = {};
		}
		i++;
	}
	for (int j = 0; j < 3; j++) {
		days = days + daysArray[j];
	}
	std::cout << "Average Days in Course for Student ID: " << studentID << " is " << days / 3 << endl;
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		Student s = *classRosterArray[i];
		string email = s.getEmailAddress();
		const std::regex pattern
		("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		if (!std::regex_match(email, pattern)) {
			std::cout << email << " is an invalid email." << endl;
		}
	}
}

void Roster::printByDegreeProgram(enum DegreeProgram degreeProgram) {
	for (int i = 0; i < 5; i++) {
		Student s = *classRosterArray[i];
		if (s.getDegreeProgram() == degreeProgram) {
			s.print(s);
		}
	}
}

void Roster::parse(string studentData) {
	size_t rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysToComplete1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysToComplete2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysToComplete3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string strDegreeProgram = studentData.substr(lhs, rhs - lhs);

	DegreeProgram degree = DegreeProgram::SOFTWARE;

	if (strDegreeProgram == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	}
	else if (strDegreeProgram == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}
	else if (strDegreeProgram == "SOFTWARE") {
		degree = DegreeProgram::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysToComplete1, daysToComplete2, daysToComplete3, degree);
}

Student* Roster::getClassRosterArray(int i) {
	return classRosterArray[i];
}

Roster::~Roster() {
	delete *classRosterArray;
	std::cout << "DONE";
}