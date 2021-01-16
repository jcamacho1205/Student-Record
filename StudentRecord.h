/*
Programmer: Jonathan Camacho
ID: 117820
--------------------
Student Record Class
--------------------
*/
#include <iostream>
#include <string>
using namespace std;
#pragma once

class StudentRecord
{
private:
	string student;
	int ID, finalGrade;
public:
	//Exception class
	class NegativeID
	{};
	
	StudentRecord();
	StudentRecord(string s, int id, int FG);
	~StudentRecord();

	//Mutator
	void setStudent(string s);
	void setID(int id);
	void setFinalGrade(int FG);

	//Accessors
	string getStudent();
	int getID();
	int getFinalGrade();

	//Validation
	bool validateGrade(int grade);
	bool validateString(string name);

	//Display
	string letterGrade();
	void displayRoster();
};
