#ifndef STUDENTS_H
#define STUDENTS_H

class Students
{
private:
	int studentNumber;
	char studentName[51];
	double GPA;
public:
	void setStudentNumber(int);
	void setStudentName(char*);
	void setGPA(double);
	void getStudentName(char*) const;
	int getStudentNumber() const;
	double getStudentGPA() const;
};

#endif