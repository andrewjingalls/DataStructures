/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA5: LazyBST
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "LazyBST.h"
#include <iostream>
using namespace std;

class Student{
    public:
        Student();
        Student(int studentID, string name, string level, string major, double GPA, int advisorID);
        Student(int studentID);
        virtual ~Student();
        void printStudentInfo(int studentID);
        bool operator==(const Student& other) const;
        bool operator!=(const Student& other) const;
        bool operator<(const Student& other) const;
        bool operator>(const Student& other) const;
        bool operator<=(const Student& other) const;
        bool operator>=(const Student& other) const;

        //getters and setters for all variables
        int getStudentID();
        void setStudentID(int studentID);
        int getAdvisorID();
        void setAdvisorID(int advisorID);

    private:
        int m_studentID;
        string m_name;
        string m_level;
        string m_major;
        double m_GPA;
        int m_advisorID;
};

#endif