//  Created by Billy Payne

#include "Student.h"
#include <iostream>
#include <iomanip>

using namespace std;

Student::Student()// constructor to be set at inital default values--
{
    //pointer name to be converted into variables
    this->studentID = "";//specifying empty variables to not print errors
    this->fName = "";
    this->lName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < daysArray; i++) this->days[i] = 0;//loops over array data table then sets any default values to 0
    this->degreeType = DegreeType::SECURITY;//sets default degree type to software using data already established in Degree.h
}

Student::Student(string studentID, string fName, string lName, string email, int age, int days[], DegreeType degreeType)//full constructor
{
    //(pointer_name)->(variable_name)
    this->studentID = studentID;
    this->fName = fName;
    this->lName = lName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysArray; i++) this->days[i] = days[i];
    this->degreeType = degreeType;
}

Student::~Student() {}//destructor does nothing because nothing is created dynamically but write it anyway; always write the desctructor

//getters or accessors
string Student::getID() { return this->studentID; }
string Student::getFName() { return this->fName; }
string Student::getLName() { return this->lName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }//array name is a pointer; you don't want to return prices individually but the reference to them
DegreeType Student::getDegreeType() { return this->degreeType; }

//setters or mutators; needs incoming parameter
void Student::setID(string studentID) { this->studentID = studentID; }
void Student::setFName(string fName) { this->fName = fName; }
void Student::setLName(string lName) { this->lName = lName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int days[])//set each number of days individually
{
    for (int i = 0; i < daysArray; i++) this->days[i] = days[i];
}
void Student::setDegreeType(DegreeType dt) { this->degreeType = dt; }

void Student::printHeader()//print header
{
    cout << "ID" << '\t' << "First" << '\t' << "Last" << '\t' << "Email Address" << '\t' << "Age" << '\t' << "Days to Complete" << '\t' << "Degree" << std::endl;//format of printout
}

void Student::print()
{
    cout << this->getID() << '\t';//tab delimited
    cout << this->getFName() << '\t';
    cout << this->getLName() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDays()[0] << ',';//grab days individually instead of pointer
    cout << this->getDays()[1] << ',';
    cout << this->getDays()[2] << '\t';
    cout << degreeTypeStrings[this->getDegreeType()] << '\n';//degreeType to string; is an int but uses Degree.h for string
}