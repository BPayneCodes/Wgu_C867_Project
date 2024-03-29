//  Created by Billy Payne

#pragma once
#include "Student.h"

class Roster
{
public:
    int lastIndex = -1;
    const static int studentDataTable = 5;
    Student* classRosterArray[studentDataTable]; //not decalred dynamically

public:
    //parse method parses set of comma delimted strings and extracts data
    void parse(string row);
    //pulls student data and creates student object in roster
    void add(string sID,
        string sFName,
        string sLName,
        string sEmail,
        int sAge,
        int d1,
        int d2,
        int d3,
        DegreeType dt);
    void printAll();//calls print() for each book
    void printByDegreeType(DegreeType dt);//degree type passed in, print by degree type
    void printInvalidEmails();//a valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
    void printAverageDays(string studentID);//prints average days used for each class
    bool removeStudentByID(string studentID);//find student and remove
    ~Roster();//destructor

    
};
