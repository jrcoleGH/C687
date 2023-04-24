#include <iostream>
#include <string>
#include "student.h"
using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < 3; i++) {
		this->daysToComplete[i] = {};
	}
	this->degree = DegreeProgram::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysToComplete1, int daysToComplete2, int daysToComplete3, enum DegreeProgram degree) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this-> age = age;
	this->daysToComplete[0] = { daysToComplete1 };
	this->daysToComplete[1] = { daysToComplete2 };
	this->daysToComplete[2] = { daysToComplete3 };
	this-> degree = degree;
}

void Student::setStudentID(string ID) {
	studentID = ID;
}

void Student::setFirstName(string first) {
	firstName = first;
}

void Student::setLastName(string last) {
	lastName = last;
}

void Student::setEmailAddress(string email) {
	emailAddress = email;
}

void Student::setAge(int studentAge) {
	age = studentAge;
}

void Student::setDaysToComplete(int days[3]) {
	for (int i = 0; i < 3; i++) {
		daysToComplete[i] = days[i];
	}
}

void Student::setDegreeProgram(enum DegreeProgram degreeProgram) {
	degree = degreeProgram;
}

string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int* Student::getDaysToComplete() {
	return daysToComplete;
}

enum DegreeProgram Student::getDegreeProgram() {
	return degree;
}

void Student::print(Student s) {
	string d;

	switch (s.getDegreeProgram()) {
		case DegreeProgram::SECURITY:
			d = "SECURITY";
			break;
		case DegreeProgram::NETWORK:
			d = "NETWORK";
			break;
		case DegreeProgram::SOFTWARE:
			d = "SOFTWARE";
			break;
	}

	std::cout << s.getStudentID();
	std::cout << "\tFirst Name: " << s.getFirstName();
	std::cout << "\tLast Name: " << s.getLastName();
	std::cout << "\tAge: " << s.getAge() << "\tDays In Course: { ";
	for (int i = 0; i < 3; i++) {
		std::cout << s.getDaysToComplete()[i] << ' ';
	}
	std::cout << "}";
	std::cout << "\tDegree Program: " << d;
	std::cout << endl;
}