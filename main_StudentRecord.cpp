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

const int NUM_STUDENTS = 40;

int main()
{
	/*//Testing
	StudentRecord student1; //Default constructor
	StudentRecord student2("Jonathan Camacho", 117820, 95); //Constructor
	string name;
	*/

	StudentRecord classRoster[NUM_STUDENTS];
	string name;
	int numStudents, count, ID, grade;

	cout << "\nEnter the amount of students in your class[1-30]: ";
	cin >> numStudents;
	while (numStudents < 1 || numStudents > 30)
	{
		cout << "Error; invalid amount.\n"
			<< "Enter an amount from 1 to 30: ";
		cin >> numStudents;
	}
	for (count = 0; count < numStudents; count++)
	{
		cin.ignore();
		cout << "\nStudent " << count + 1 << endl
			<< "Enter the student's name: ";
		getline(cin, name);
		classRoster[count].setStudent(name);
		cout << "Enter " << classRoster[count].getStudent() << "'s ID number: ";
		cin >> ID;
		try		//Exception Class Try & Catch
		{
			classRoster[count].setID(ID);
		}
		catch (StudentRecord::NegativeID)
		{
			cout << "Error; a negative ID was entered.\n";
		}
		cout << "Enter " << classRoster[count].getStudent() << "'s final grade: ";
		cin >> grade;
		classRoster[count].setFinalGrade(grade);
	}
	cout << "\n\t\tClass Roster\n"
		<< setw(14)
		<< "Student"
		<< setw(10)
		<< "ID"
		<< setw(10)
		<< "Grade\n"
		<< "----------------------------------------------\n";
	for (count = 0; count < numStudents; count++)
	{
		classRoster[count].displayRoster();
	}

	//Menu of Operations
	int choice;
	do
	{
		cout << "--------------------------------------------\n"
			<< "Do you wish to...\n"
			<< "1. Add another student record?\n"
			<< "2. Remove a student record?\n"
			<< "3. Display a particular student's record?\n"
			<< "4. Display class average?\n"
			<< "5. Quit program?\n"
			<< "Enter your choice via integer: ";
		cin >> choice;
		while (choice < 1 || choice > 5)
		{
			cout << "Invalid choice; enter a valid integer: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			numStudents++;
			cin.ignore();
			cout << "\nStudent " << numStudents << endl
				<< "Enter the student's name: ";
			getline(cin, name);
			classRoster[numStudents - 1].setStudent(name);
			cout << "Enter " << classRoster[numStudents - 1].getStudent() << "'s ID number: ";
			cin >> ID;
			try			//Exception Class Try & Catch
			{
				classRoster[numStudents - 1].setID(ID);
			}
			catch (StudentRecord::NegativeID)
			{
				cout << "Error; a negative ID was entered.\n";
			}
			cout << "Enter " << classRoster[numStudents - 1].getStudent() << "'s final grade: ";
			cin >> grade;
			classRoster[numStudents - 1].setFinalGrade(grade);
			cout << "\n\t\tClass Roster\n"
				<< setw(14)
				<< "Student"
				<< setw(10)
				<< "ID"
				<< setw(10)
				<< "Grade\n"
				<< "----------------------------------------------\n";
			for (count = 0; count < numStudents; count++)
			{
				classRoster[count].displayRoster();
			}
			break;
		case 2:
			int removeID;
			cout << "\nEnter the ID of the student whose record you wish to remove: ";
			cin >> removeID;
			for (count = 0; count < numStudents; count++)
			{
				if (removeID == classRoster[count].getID()) //the array slot is still taken, 
				{											//but it does not affect the average or other operations
					classRoster[count].setStudent("");
					classRoster[count].setID(0);
					classRoster[count].setFinalGrade(0);
				}
			}
			cout << "\n\t\tClass Roster\n"
				<< setw(14)
				<< "Student"
				<< setw(10)
				<< "ID"
				<< setw(10)
				<< "Grade\n"
				<< "----------------------------------------------\n";
			for (count = 0; count < numStudents; count++)
			{
				classRoster[count].displayRoster();
			}
			break;
		case 3:
			int displayID;
			cout << "\nEnter the ID of the student whose record you wish to display: ";
			cin >> displayID;
			for (count = 0; count < numStudents; count++)
			{
				if (displayID == classRoster[count].getID())
				{
					cout << setw(14)
						<< "Student"
						<< setw(10)
						<< "ID"
						<< setw(10)
						<< "Grade\n"
						<< "----------------------------------------------\n";
						classRoster[count].displayRoster();
				}
			}
			break;
		case 4:
			int average, totalGrade, validStudents;
			totalGrade = 0;
			validStudents = numStudents;
			for (count = 0; count < numStudents; count++)
			{
				if (classRoster[count].getID() != -1) //because of the Remove Student option
					totalGrade += classRoster[count].getFinalGrade(); 
				if (classRoster[count].getID() == -1) // ^
					validStudents--;
			}
			average = totalGrade / validStudents; //accurate average everytime
			cout << "\nThe average score for the class is " << average << endl;
			break;
		case 5:
			cout << "\nProgram ending...\n";
			break;
		};
	} while (choice != 5);
	system("pause");
	return 0;
}
/* Output for Exception Class version:

Enter the amount of students in your class[1-30]: 1

Student 1
Enter the student's name: Jonathan Camacho
Enter Jonathan Camacho's ID number: -1
Error; a negative ID was entered.
Enter Jonathan Camacho's final grade: 100

				Class Roster
	   Student        ID    Grade
----------------------------------------------
Jonathan Camacho         0    100 A
--------------------------------------------
Do you wish to...
1. Add another student record?
2. Remove a student record?
3. Display a particular student's record?
4. Display class average?
5. Quit program?
Enter your choice via integer: 1

Student 2
Enter the student's name: Alex
Enter Alex's ID number: -10
Error; a negative ID was entered.
Enter Alex's final grade: 90

				Class Roster
	   Student        ID    Grade
----------------------------------------------
Jonathan Camacho         0    100 A
		  Alex         0     90 A-
--------------------------------------------
Do you wish to...
1. Add another student record?
2. Remove a student record?
3. Display a particular student's record?
4. Display class average?
5. Quit program?
Enter your choice via integer: 5

Program ending...
Press any key to continue . . .
*/


/*Output

Enter the amount of students in your class[1-30]: 2

Student 1
Enter the student's name: Jonathan
Enter Jonathan's ID number: 1
Enter Jonathan's final grade: 100

Student 2
Enter the student's name: Al3x
Invalid string; enter a valid name: Alex
Enter Alex's ID number: 2
Enter Alex's final grade: 95

				Class Roster
	   Student        ID    Grade
----------------------------------------------
	  Jonathan         1    100 A
		  Alex         2     95 A
--------------------------------------------
Do you wish to...
1. Add another student record?
2. Remove a student record?
3. Display a particular student's record?
4. Display class average?
5. Quit program?
Enter your choice via integer: 1

Student 3
Enter the student's name: Victor Vega
Enter Victor Vega's ID number: 3
Enter Victor Vega's final grade: 80

				Class Roster
	   Student        ID    Grade
----------------------------------------------
	  Jonathan         1    100 A
		  Alex         2     95 A
   Victor Vega         3     80 B-
--------------------------------------------
Do you wish to...
1. Add another student record?
2. Remove a student record?
3. Display a particular student's record?
4. Display class average?
5. Quit program?
Enter your choice via integer: 2

Enter the ID of the student whose record you wish to remove: 2

				Class Roster
	   Student        ID    Grade
----------------------------------------------
	  Jonathan         1    100 A
					  -1      0 F
   Victor Vega         3     80 B-
--------------------------------------------
Do you wish to...
1. Add another student record?
2. Remove a student record?
3. Display a particular student's record?
4. Display class average?
5. Quit program?
Enter your choice via integer: 3

Enter the ID of the student whose record you wish to display: 1
	   Student        ID    Grade
----------------------------------------------
	  Jonathan         1    100 A
--------------------------------------------
Do you wish to...
1. Add another student record?
2. Remove a student record?
3. Display a particular student's record?
4. Display class average?
5. Quit program?
Enter your choice via integer: 4

The average score for the class is 90
--------------------------------------------
Do you wish to...
1. Add another student record?
2. Remove a student record?
3. Display a particular student's record?
4. Display class average?
5. Quit program?
Enter your choice via integer: 5

Program ending...
Press any key to continue . . .
*/