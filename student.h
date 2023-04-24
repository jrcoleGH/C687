#include <string>
#include "degree.h"
using namespace std;

class Student {
public:
	Student();
	Student(string ID, string first, string last, string email, int studentAge,
		int daysToComplete1, int daysToComplete2, int daysToComplete3, enum DegreeProgram degree);
	void setStudentID(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmailAddress(string);
	void setAge(int);
	void setDaysToComplete(int[3]);
	void setDegreeProgram(enum DegreeProgram);
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysToComplete();
	enum DegreeProgram getDegreeProgram();
	void print(Student);

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[3];
	enum DegreeProgram degree;
};