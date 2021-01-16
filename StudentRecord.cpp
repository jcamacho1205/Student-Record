/*
Programmer: Jonathan Camacho
ID: 117820
--------------------
Student Record Class
--------------------
Design a class or set of classes (INCLUDE ONLY THE CLASS DEFINITION INCLUDING SETTERS, GETTERS, CONSTRUCTOR AND DESTRUCTOR)
for use in a program that maintains a class roster.
For each student, store the student’s name, id, and final grade score in the range 0-100.

The program will allow student records to be added or removed;
display the record of a particular student, identified by id, with the grade displayed as a number
and as a letter, and display the average score for the class.

The appropriate letter grade for a particular score is:
93-100 A, 90-92 A-, 87-89 B+, 83-86 B, 80-82 B-, 77-79 C+, 73-76 C, 70-72 C-, 67-69 D+, 60-66 D, 0-59F
*/
#include <iostream>
#include "StudentRecord.h"
#include <string>
#include <iomanip>
using namespace std;


StudentRecord::StudentRecord()
{
	setStudent("");
	setID(0);
	setFinalGrade(0);
}
StudentRecord::StudentRecord(string s, int id, int FG)
{
	setStudent(s);
	setID(id);
	setFinalGrade(FG);
}
StudentRecord::~StudentRecord()
{
	cout << "Sending Godzilla...\n"
		<< "Data destroyed.\n";
}

//Mutator
void StudentRecord::setStudent(string s)
{
	while (!validateString(s))
	{
		cin.ignore();
		cout << "Invalid string; enter a valid name: ";
		getline(cin, s);
	}
	student = s;
}
void StudentRecord::setID(int id)
{
	if (id >= 0)
		ID = id;
	else
		throw NegativeID();
}
void StudentRecord::setFinalGrade(int FG)
{
	while (!validateGrade(FG))
	{
		cout << "Enter a valid final Grade [0-100]: ";
		cin >> FG;
	}
	finalGrade = FG;
}

//Accessors
string StudentRecord::getStudent()
{
	return student;
}
int StudentRecord::getID()
{
	return ID;
}
int StudentRecord::getFinalGrade() 
{
	return finalGrade;
}

//Validation
bool StudentRecord::validateGrade(int grade) 
{
	bool condition;
	if ((grade >= 0) && (grade <= 100))
	{
		condition = true;
	}
	else
	{
		condition = false;
	}
	return condition;
}

bool StudentRecord::validateString(string name)
{
	//Métodos de string a c-string no me funcionan; debido a que se necesita un CONST para inicializar un array.
	//int size = static_cast<int>(name.length()); //me esta dando errores
	/*char* charArray = new char [name.length() + 1];
	strcpy_s(charArray, name.length() + 1, name.c_str());//tambien

	bool validation;
	for (int i = 0; i < name.length(); i++)
	{
		if (isalpha(*charArray + i) || isspace(*charArray + i))
		{
			validation = true;
		}
		else
		{
			validation = false;
			break;
		}
	}
	delete[] charArray; //para que no me pese la computadora
	return validation;*/
	for (const char c : name) 
	{
		if (!isalpha(c) && !isspace(c))
			return false;
	}
	return true;
}

//Display

string StudentRecord::letterGrade() //copiado de StudentRecord.cpp de Zayira Jordán Conde
{
	if (!validateGrade(finalGrade)) 
		return "ERROR";
	const int NUMBER_CATEGORIES = 11;
	const string GRADE_LETTER[] = { "F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A" };
	const int LOWEST_GRADE_SCORE[] = { 0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93 };
	int category = 0;
	while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= finalGrade)
		category++;
	return GRADE_LETTER[category - 1];
}

void StudentRecord::displayRoster()
{
	cout << setw(14)
		<< getStudent()
		<< setw(10)
		<< getID()
		<< setw(7)
		<< getFinalGrade() << " " << letterGrade() << endl;
}