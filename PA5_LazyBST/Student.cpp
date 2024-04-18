/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA5: LazyBST
*/

#include "Student.h"

//Default constructor
Student::Student(){
    m_studentID = 0;
    m_name = "";
    m_level = "";
    m_major = "";
    m_GPA = 0.0;
    m_advisorID = 0;
}

//Overloaded constructor
Student::Student(int ID, string name, string level, string major, double GPA, int advisorID){
    m_studentID = ID;
    m_name = name;
    m_level = level;
    m_major = major;
    m_GPA = GPA;
    m_advisorID = advisorID;
}

//Overloaded constructor that takes in only the student ID
Student::Student(int ID){
    m_studentID = ID;
    m_name = "";
    m_level = "";
    m_major = "";
    m_GPA = 0.0;
    m_advisorID = 0;
}

//Destructor
Student::~Student(){

}

//Method for printing out the student info given a student ID
void Student::printStudentInfo(int studentID){
    cout << "---------------" << endl;
    cout << "Student ID: " << m_studentID << endl;
    cout << "Name: " << m_name << endl;
    cout << "Level: " << m_level << endl;
    cout << "Major: " << m_major << endl;
    cout << "GPA: " << m_GPA << endl;
    cout << "Advisor ID: " << m_advisorID << endl;
    cout << "---------------" << endl;
}

//Operator overloads for comparing students
bool Student::operator==(const Student& other) const{
    return m_studentID == other.m_studentID;
}

bool Student::operator!=(const Student& other) const{
    return m_studentID != other.m_studentID;
}

bool Student::operator<(const Student& other) const{
    return m_studentID < other.m_studentID;
}

bool Student::operator>(const Student& other) const{
    return m_studentID > other.m_studentID;
}

bool Student::operator<=(const Student& other) const{
    return m_studentID <= other.m_studentID;
}

bool Student::operator>=(const Student& other) const{
    return m_studentID >= other.m_studentID;
}

//Getter for student ID
int Student::getStudentID(){
    return m_studentID;
}
//Setter for student ID
void Student::setStudentID(int studentID){
    m_studentID = studentID;
}

//Getter for advisor ID
int Student::getAdvisorID(){
    return m_advisorID;
}
//Setter for advisor ID
void Student::setAdvisorID(int advisorID){
    m_advisorID = advisorID;
}