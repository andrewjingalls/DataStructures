/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA5: LazyBST
*/

#include "Faculty.h"

//Default constructor
Faculty::Faculty(){
    m_facultyID = 0;
    m_name = "";
    m_level = "";
    m_department = "";
    m_adviseeList = new DblList<int>; //use our linkedlist class for advisee list
}

//Overloaded constructor
Faculty::Faculty(int facultyID, string name, string level, string department, DblList<int>* adviseeList){
    m_facultyID = facultyID;
    m_name = name;
    m_level = level;
    m_department = department;
    m_adviseeList = adviseeList;
}

//Overloaded constructor that takes in only the faculty ID
Faculty::Faculty(int facultyID){
    m_facultyID = facultyID;
    m_name = "";
    m_level = "";
    m_department = "";
    m_adviseeList = new DblList<int>; //use our linkedlist class for advisee list
}

// Copy constructor for creating a deep copy of a faculty object
Faculty::Faculty(const Faculty& other) {
    m_facultyID = other.m_facultyID;
    m_name = other.m_name;
    m_level = other.m_level;
    m_department = other.m_department;
    m_adviseeList = new DblList<int>(*other.m_adviseeList); // Deep copy
}

//Overloaded assignment operator for creating a deep copy of a faculty object
Faculty& Faculty::operator=(const Faculty& other) {
    if (this != &other) {   //checks if the objects are the same
        delete m_adviseeList; // Delete old list

        m_facultyID = other.m_facultyID;
        m_name = other.m_name;
        m_level = other.m_level;
        m_department = other.m_department;
        m_adviseeList = new DblList<int>(*other.m_adviseeList); // makes a deep copy
    }
    return *this;
}

//Destructor, deletes the advisee list
Faculty::~Faculty(){
    delete m_adviseeList;
}

//Prints the faculty info given the faculty ID
void Faculty::printFacultyInfo(int facultyID){
    cout << "---------------" << endl;
    cout << "Faculty ID: " << m_facultyID << endl;
    cout << "Name: " << m_name << endl;
    cout << "Level: " << m_level << endl;
    cout << "Department: " << m_department << endl;
    cout << "Advisee List: " << endl;
    m_adviseeList->printList();
    cout << "---------------" << endl;
}

//Operator overloads for comparing faculty objects
bool Faculty::operator==(const Faculty& other) const{
    return m_facultyID == other.m_facultyID;
}

bool Faculty::operator!=(const Faculty& other) const{
    return m_facultyID != other.m_facultyID;
}

bool Faculty::operator<(const Faculty& other) const{
    return m_facultyID < other.m_facultyID;
}

bool Faculty::operator>(const Faculty& other) const{
    return m_facultyID > other.m_facultyID;
}

bool Faculty::operator<=(const Faculty& other) const{
    return m_facultyID <= other.m_facultyID;
}

bool Faculty::operator>=(const Faculty& other) const{
    return m_facultyID >= other.m_facultyID;
}

//Getter for the faculty ID
int Faculty::getFacultyID(){
    return m_facultyID;
}
//Setter for the faculty ID
void Faculty::setFacultyID(int facultyID){
    m_facultyID = facultyID;
}

//Method for removing a student from the advisee list
void Faculty::removeAdvisee(int studentID){
    m_adviseeList->remove(studentID);
}

//Method for adding a student to the advisee list
void Faculty::addAdvisee(int studentID){
    m_adviseeList->addBack(studentID);
}

//Method for checking if a student is in the advisee list
bool Faculty::isStudentInList(int studentID){
    return m_adviseeList->contains(studentID);
}

//Getter for the advisee list
DblList<int>* Faculty::getAdviseeList(){
    return m_adviseeList;
}
//Setter for the advisee list
void Faculty::setAdviseeList(DblList<int>* adviseeList){
    m_adviseeList = adviseeList;
}