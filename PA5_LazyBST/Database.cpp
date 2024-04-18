/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA5: LazyBST
*/

#include "Database.h"
//Default constructor
Database::Database(){
    //Creates a tree for students and a tree for faculty
    studentTree = new LazyBST<Student>();
    facultyTree = new LazyBST<Faculty>();

    //Initialize the advisee lists used later
    adviseeList1 = new DblList<int>();
    adviseeList2 = new DblList<int>();

}
//Destructor
Database::~Database(){
    //Deletes the student and faculty trees
    delete studentTree;
    delete facultyTree;
}

//Initialize the tree with a few students to the tree
void Database::initializeStudents(){
    Student student1(123, "Andrew", "Senior", "Business", 4.0, 987);
    Student student2(456, "Bob", "Junior", "Computer Science", 3.0, 654);
    Student student3(789, "Charlie", "Sophomore", "Math", 3.2, 987);
    Student student4(101, "Derek", "Freshman", "Engineering", 3.8, 654);
    addStudentToTree(student1);
    addStudentToTree(student2);
    addStudentToTree(student3);
    addStudentToTree(student4);
}

//Initialize the faculty tree with a few faculty members
void Database::initializeFaculty(){
    //Add the already initalized student's ID's to the advisee lists
    adviseeList1->addFront(123);
    adviseeList1->addFront(456);
    adviseeList2->addFront(789);
    adviseeList2->addFront(101);
    Faculty faculty1(987, "Evan", "Professor", "Business", adviseeList1);
    Faculty faculty2(654, "Frank", "Professor", "Computer Science", adviseeList2);
    addFacultyToTree(faculty1);
    addFacultyToTree(faculty2);
}

//Add a student to the student tree
void Database::addStudentToTree(Student student){
    studentTree->insert(student);
    
}

//Add a faculty member to the faculty tree
void Database::addFacultyToTree(Faculty faculty){
    facultyTree->insert(faculty);
}

//Print a student's information given the student id
void Database::printStudent(int studentID){
    //Makes a student object and copies it from the one searched for in the tree
    Student student = studentTree->search(Student(studentID));
    //Prints the copied student's info
    student.printStudentInfo(studentID);
}

//Prints a faculty member's information given the faculty id
void Database::printFaculty(int facultyID){
    //Makes a faculty object and copies it from the one searched for in the tree
    Faculty faculty = facultyTree->search(Faculty(facultyID));
    //Prints the copied faculty's info
    faculty.printFacultyInfo(facultyID);
}

//Prints all students and their info
void Database::printAllStudents(){
    //Uses a lambda function to return the student tree in order and 
    //print each student's info while also calling the getStudentID function on each student
    studentTree->returnTreeInOrder([](Student& student){
        student.printStudentInfo(student.getStudentID());
    });
}

//Prints all faculty and their info
void Database::printAllFaculty(){
    //Also uses a lambda function to return the faculty tree in order and
    //print each faculty's info while also calling the getFacultyID function on each faculty
    facultyTree->returnTreeInOrder([](Faculty& faculty){
        faculty.printFacultyInfo(faculty.getFacultyID());
    });
}

//Takes in the students variables as parameters and creates a new student object
//Then adds the student to the tree
void Database::addStudent(int studentID, string name, string level, string major, double GPA, int advisorID){
    Student newStudent(studentID, name, level, major, GPA, advisorID);
    addStudentToTree(newStudent);
}

//Given the student id, deletes the student from the tree
void Database::deleteStudent(int studentID){
    studentTree->remove(Student(studentID));
}

//Given the faculty id, deletes the faculty from the tree
void Database::deleteFaculty(int facultyID){
    facultyTree->remove(Faculty(facultyID));
}

//Method for changing a students advisor given the student id and the new faculty id
void Database::changeAdvisor(int studentID, int newFacultyID){
    //Search tree for student given the ID
    Student student = studentTree->search(Student(studentID));
    //Get the student's current advisor
    int oldFacID = student.getAdvisorID();
    //Search tree for faculty given the ID
    Faculty oldFaculty = facultyTree->search(Faculty(oldFacID));
    //Remove student from old faculty's advisee list
    oldFaculty.removeAdvisee(studentID);

    //Set student's advisor to new faculty
    student.setAdvisorID(newFacultyID);
    //Remove the student from the student tree with the old advisor
    studentTree->remove(Student(studentID));
    //Insert the student back into the student tree with updated advisor
    studentTree->insert(student);
    //Search tree for new faculty given the ID
    Faculty newFaculty = facultyTree->search(Faculty(newFacultyID));
    //Add student to new faculty's advisee list
    newFaculty.addAdvisee(studentID);
    //Remove the old faculty from the faculty tree
    facultyTree->remove(Faculty(oldFacID));
    //Reinsert the old faculty back into the faculty tree with the updated info
    facultyTree->insert(oldFaculty);
}

//Method for removing an advisee from a faculty member given the faculty id and the student id
void Database::removeAdvisee(int facultyID, int studentID){
    //search faculty tree given the ID
    Faculty faculty = facultyTree->search(Faculty(facultyID));
    //Remove student from faculty's advisee list
    faculty.removeAdvisee(studentID);
    //Makes a student object and copies it from the one searched for in the tree
    Student student = studentTree->search(Student(studentID));
    //Sets the student's advisor to 0, meaning they have no advisor now
    student.setAdvisorID(0);
    //Remove student from student tree
    studentTree->remove(Student(studentID));
    //insert student back into student tree with updated information
    studentTree->insert(student);
    //remove faculty from faculty tree
    facultyTree->remove(Faculty(facultyID));
    //insert faculty back into faculty tree with updated information
    facultyTree->insert(faculty);
}

//Method for checking if the student tree is balanced
bool Database::isStudentTreeBalanced(LazyBST<Student>* inputStudentTree){
    return inputStudentTree->isTreeBalanced();
}

//Method for rebalancing the student tree
void Database::reblanceStudentTree(){
    studentTree->rebalance();
}

//Method for checking if the faculty tree is balanced
bool Database::isFacultyTreeBalanced(LazyBST<Faculty>* inputFacultyTree){
    return inputFacultyTree->isTreeBalanced();
}

//Method for rebalancing the faculty tree
void Database::reblanceFacultyTree(){
    facultyTree->rebalance();
}

//Getter for the student tree
LazyBST<Student>* Database::getStudentTree(){
    return studentTree;
}

//Getter for the faculty tree
LazyBST<Faculty>* Database::getFacultyTree(){
    return facultyTree;
}

//Method for checking if a student is in a faculty's advisee list
bool Database::isStudentInFacultyList(int studentID, int facultyID){
    //search tree for faculty given the ID
    Faculty faculty = facultyTree->search(Faculty(facultyID));
    //check if student is in faculty's advisee list
    return faculty.isStudentInList(studentID);
}

//Method for printing a faculty's advisee list given the faculty id
void Database::printListOfFacultyIDS(){
    //returns each faculty and prints the faculty id for each faculty
    facultyTree->returnTreeInOrder([](Faculty& faculty){
        cout << faculty.getFacultyID() << endl;
    });
}