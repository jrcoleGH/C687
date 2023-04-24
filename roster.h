#include <string>
#include "student.h"
using namespace std;

class Roster {
public:
	Roster();
	~Roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysToComplete1, int daysToComplete2, int daysToComplete3, enum DegreeProgram degree);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(enum DegreeProgram degreeProgram);
	void parse(string studentData);
	Student* getClassRosterArray(int i);

private:
	int count;
	Student* classRosterArray[5];
};