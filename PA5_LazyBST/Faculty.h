/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA5: LazyBST
*/

#ifndef FACULTY_H
#define FACULTY_H

#include "LazyBST.h"
#include "DblList.h"
#include <iostream>
using namespace std;

class Faculty{
    public:
        Faculty();                                                                 //fix the list
        Faculty(int facultyID, string name, string level, string department, DblList<int>* adviseeList); 
        Faculty(int facultyID);
        Faculty(const Faculty& other);
        Faculty& operator=(const Faculty& other);
        virtual ~Faculty();
        void printFacultyInfo(int facultyID);
        bool operator==(const Faculty& other) const;
        bool operator!=(const Faculty& other) const;
        bool operator<(const Faculty& other) const;
        bool operator>(const Faculty& other) const;
        bool operator<=(const Faculty& other) const;
        bool operator>=(const Faculty& other) const;
    
        void removeAdvisee(int studentID);
        void addAdvisee(int studentID);
        bool isStudentInList(int studentID);

        int getFacultyID();
        void setFacultyID(int facultyID);
        DblList<int>* getAdviseeList();
        void setAdviseeList(DblList<int>* adviseeList);

    private:
        int m_facultyID;
        string m_name;
        string m_level;
        string m_department;
        DblList<int>* m_adviseeList;
};

#endif