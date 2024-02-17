//  Created by Billy Payne

#include <iostream>
#include "Roster.h"
using namespace std;

//using std::endl;
//main program 
int main()
{
    cout << "Course: C867 Scripting and Programming - Applications\n" << "Programming Language: C++\n" << "ID: 010047760\n" << "Name: Billy Payne " << std::endl << std::endl;

    //parsing for string
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Billy,Payne,Billypayn20@gmail.com,35,16,20,23,SOFTWARE"
    };

    const int studentDataTable = 5;//sets table array size
    Roster roster;//creates report using default constructor; defaults set to 0

    for (int i = 0; i < studentDataTable; i++) roster.parse(studentData[i]);
    cout << "Displaying all students:" << std::endl;
    roster.printAll();
    cout << std::endl;
    //displaying for all students

    cout << "Displaying all software students:" << std::endl;
    roster.printByDegreeType(SOFTWARE);
    cout << std::endl;
    //students in the software degree program

    cout << "Displaying invalid email addess: " << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;
    //shows and prints students with an incorrect email address

    cout << "Displaying average days per class:" << std::endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        roster.printAverageDays(roster.classRosterArray[i]->getID());
    }
    cout << std::endl;
    //shows the average number of days each student spends in 3 classes then to be put back into array

    cout << "Remove student A3." << std::endl;
    roster.removeStudentByID("A3");
    cout << std::endl;
    //only removing student A3 and print all remaining students

    //removing student A3 for all pointers
    cout << "Remove student A3." << std::endl;
    roster.removeStudentByID("A3");
    cout << std::endl << std::endl;

}