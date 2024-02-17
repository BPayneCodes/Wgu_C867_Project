//  Created by Billy Payne 

//student housing list
#include <iostream>
#include <string>
#include "Roster.h"
#include <iomanip>
using namespace std;


void Roster::parse(string studentdata)//diffrentiates each row
{
    //main parse for student index data
    int rshs = studentdata.find(',');//locates comma to move index
    string sID = studentdata.substr(0, rshs);

    int lths = rshs + 1;//moves past last comma
    rshs = studentdata.find(',', lths);
    string sFName = studentdata.substr(lths, rshs - lths);//locates first name

    lths = rshs + 1;//searching
    rshs = studentdata.find(',', lths);
    string sLName = studentdata.substr(lths, rshs - lths);//locates last name

    lths = rshs + 1; //searching
    rshs = studentdata.find(",", lths);
    string sEmail = studentdata.substr(lths, rshs - lths);

    lths = rshs + 1; //searching
    rshs = studentdata.find(",", lths);
    int sAge = stoi(studentdata.substr(lths, rshs - lths));

    lths = rshs + 1; //searching
    rshs = studentdata.find(",", lths);
    int d1 = stod(studentdata.substr(lths, rshs - lths));//starting number of days

    lths = rshs + 1; //searching
    rshs = studentdata.find(",", lths);
    int d2 = stod(studentdata.substr(lths, rshs - lths));

    lths = rshs + 1; //searching
    rshs = studentdata.find(",", lths);
    int d3 = stod(studentdata.substr(lths, rshs - lths));

    lths = rshs + 1;
    rshs = studentdata.find(",", lths);

    DegreeType dt = SECURITY; //pulls all three criteria into headers for data processing

    if (studentdata.at(lths) == 'S' && studentdata.at(lths + 1) == 'E') dt = SECURITY;
    else if (studentdata.at(lths) == 'S' && studentdata.at(lths + 1) == 'O') dt = SOFTWARE;
    else if (studentdata.at(lths) == 'N') dt = NETWORK;

    //parses the data underneath header arrays
    add(sID, sFName, sLName, sEmail, sAge, d1, d2, d3, dt);

}

// combines strings and creates object in roster.h
void Roster::add(string studentID, string fName, string lName, string email, int age, int d1, int d2, int d3, DegreeType dt)
{
    //puts data back into array for reconstruction
    int darr[3] = { d1, d2, d3 };
    classRosterArray[++lastIndex] = new Student(studentID, fName, lName, email, age, darr, dt);// full constructor
}

// delimited output for all students in array
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

//invalid email searching for roster 
void Roster::printInvalidEmails()
{
    bool any = false;
    //checking for invalid emails
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string email = (classRosterArray[i]->getEmail());
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
        {
            any = true;
       
            cout << email << ":" << classRosterArray[i]->getFName() << std::endl;
            //prints invalid emails
        }
    }
    if (!any) cout << "NONE" << std::endl;
    //prints for no invalid IDs
}


void Roster::printAverageDays(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            cout << studentID << ":";
            cout << (classRosterArray[i]->getDays()[0] +
                classRosterArray[i]->getDays()[1] +
                classRosterArray[i]->getDays()[2]) / 3 << std::endl;
            
        }
    }
}

//display any of the students with the same degree type
void Roster::printByDegreeType(DegreeType dt)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeType() == dt) classRosterArray[i]->print();
    }
    cout << std::endl;
}

//taking student id for the removed students
bool Roster::removeStudentByID(string studentID)

{
    bool success = false; //assuming a student does not exist searches down the list for student
    for (int i = 0; i <= Roster::lastIndex; i++)
        
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            success = true;//when a student may be found
            if (i < studentDataTable - 1)
            {
                Student* temp = classRosterArray[i];//current student will be swapped out for the last one
                classRosterArray[i] = classRosterArray[studentDataTable - 1];//moves around the pointer in memory
                classRosterArray[studentDataTable - 1] = temp;
            }
            Roster::lastIndex--;//only the last student is hidden but no destroyed
        }
    }
    if (success)
    {
        cout << studentID << " removed from roster." << std::endl << std::endl;
        this->printAll();//doesn't display destroyed students
    }
    //prints for student ID;s that have already been taken out
    else cout << studentID << " not found." << std::endl << std::endl;;
    return 0;
}
//the list that gets removed--
Roster::~Roster()
//removes objects that are dynamically allocated
{
    cout << "Destructor summoned--" << std::endl << std::endl;
    for (int i = 0; i < studentDataTable; i++)
        //size of numDegrees stays the same unlike lastIndex
    {
        //for removing students from roster array
        cout << "Removing student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
        //set to nullptr so it doesn't go to address otherwise program would fail
    }
}