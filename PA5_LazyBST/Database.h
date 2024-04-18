/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA5: LazyBST
*/

#ifndef DATABASE_H
#define DATABASE_H

#include "LazyBST.h"
#include "Student.h"
#include "Faculty.h"
#include <iostream>
using namespace std;

class Database{
    public:
        Database();
        virtual ~Database();
        void initializeStudents();
        void initializeFaculty();
        void addStudentToTree(Student student);
        void addFacultyToTree(Faculty faculty);
        bool isStudentTreeBalanced(LazyBST<Student>* inputStudentTree);
        bool isFacultyTreeBalanced(LazyBST<Faculty>* inputFacultyTree);
        void reblanceStudentTree();
        void reblanceFacultyTree();
        LazyBST<Student>* getStudentTree();
        LazyBST<Faculty>* getFacultyTree();
        bool isStudentInFacultyList(int studentID, int facultyID); 
        void printListOfFacultyIDS();

        void printAllStudents();
        void printAllFaculty();
        void printStudent(int studentID);
        void printFaculty(int facultyID);
        void addStudent(int studentID, string name, string level, string major, double GPA, int advisorID);
        void deleteStudent(int studentID);
        void deleteFaculty(int facultyID);
        void changeAdvisor(int studentID, int NewFacultyID);
        void removeAdvisee(int facultyID, int studentID);

    private:
        LazyBST<Student>* studentTree;
        LazyBST<Faculty>* facultyTree;
        DblList<Student>* listOfStudents;

        DblList<int>* adviseeList1;
        DblList<int>* adviseeList2;
};

#endif