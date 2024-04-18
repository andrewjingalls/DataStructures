/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA5: LazyBST
*/

#include "Database.h"
#include "LazyBST.h"
#include <sstream>
#include <fstream>
int main(){
    //Create a database object
    Database* dataBase = new Database();
    //Initialize the database with the students and faculty
    dataBase->initializeStudents();
    dataBase->initializeFaculty();
    bool exit = false;
    //While the user does not want to exit, keep running the program
    while(exit == false){
        cout << "Please choose one of the following options:" << endl;
        cout << "1. Print all students and their information" << endl;
        cout << "2. Print all faculty and their information" << endl;
        cout << "3. Find and display student information given the student id" << endl;
        cout << "4. Find and display faculty information given the faculty id" << endl;
        cout << "5. Add a new student" << endl;
        cout << "6. Delete a student given the id" << endl;
        cout << "7. Add a new faculty member" << endl;
        cout << "8. Delete a faculty member given the id" << endl;  
        cout << "9. Change a student’s advisor given the student id and the new faculty id" << endl;
        cout << "10. Remove an advisee from a faculty member given the ids" << endl;
        cout << "11. Exit" << endl;
        cout << endl;
        int option = 0;
        cin >> option;
        if(option == 0){
            cout << "Please enter a valid option." << endl;
        }
        else if(option == 1){
            //Print all students and their information (sorted by ascending id #)
            cout << "Printing all students:" << endl;
            dataBase->printAllStudents();

        }
        else if(option == 2){
            //Print all faculty and their information (sorted by ascending id #)
            cout << "Printing all faculty:" << endl;
            dataBase->printAllFaculty();
        }
        else if(option == 3){
            //Find and display student information given the student id
            cout << "Please enter the student's ID number: " << endl;
            int studentID;
            cin >> studentID;
            dataBase->printStudent(studentID);
        }
        else if(option == 4){
            //Find and display faculty information given the faculty id
            cout << "Please enter the faculty's ID number: " << endl;
            int facultyID;
            cin >> facultyID;
            dataBase->printFaculty(facultyID);
        }
        else if(option == 5){
            //Add a new student
            int studentID;
            string name;
            string level;
            string major;
            double GPA;
            int advisorID;
            cout << "Please enter the student's ID number: " << endl;
            cin >> studentID;
            cout << "Please enter the student's name: " << endl;
            cin >> name;
            cout << "Please enter the student's level: " << endl;
            cin >> level;
            cout << "Please enter the student's major: " << endl;
            cin >> major;
            cout << "Please enter the student's GPA: " << endl;
            cin >> GPA;
            cout << "Please enter the student's advisor's ID number, here are a list of them:" << endl;
            dataBase->printListOfFacultyIDS();
            cin >> advisorID;
            Faculty advisor(advisorID);
            //If the faculty ID does not exist, keep asking for a valid ID
            if(!dataBase->getFacultyTree()->contains(Faculty(advisorID))){
                while(!dataBase->getFacultyTree()->contains(Faculty(advisorID))){
                    cout << "Faculty ID does not exist. Please try again." << endl;
                    cout << "Please enter the student's advisor's ID number: " << endl;
                    cin >> advisorID;
                    advisor = Faculty(advisorID);
                }
            }
            //Add the student to the tree
            dataBase->addStudent(studentID, name, level, major, GPA, advisorID);
            //Add the student to the faculty's advisee list
            dataBase->changeAdvisor(studentID, advisorID);
            
            cout << "Successfully added student." << endl;
            //Check if the tree is balanced, if not rebalance the tree
            if(dataBase->getStudentTree()->isTreeBalanced() != true){
                dataBase->reblanceStudentTree();
            }
        }
        else if(option == 6){
            //Delete a student given the id
            cout << "Please enter the student's ID number: " << endl;
            int studentID;
            cin >> studentID;
            dataBase->deleteStudent(studentID);
            cout << "Successfully deleted student." << endl;

            //delete student from current faulty's advisee list
            int facultyID = dataBase->getStudentTree()->search(Student(studentID)).getAdvisorID();
            dataBase->removeAdvisee(facultyID, studentID);

            //After deleting a student, check if the tree is balanced, if not rebalance the tree
            if(dataBase->getStudentTree()->isTreeBalanced() != true){
                dataBase->reblanceStudentTree();
            }
        }
        else if(option == 7){
            //Add a new faculty member
            int facultyID;
            string name;
            string level;
            string department;
            DblList<int>* adviseeList = new DblList<int>();
            string listOfAdvisees;
            cout << "Please enter the faculty's ID number: " << endl;
            cin >> facultyID;
            cout << "Please enter the faculty's name: " << endl;
            cin >> name;
            cout << "Please enter the faculty's level: " << endl;
            cin >> level;
            cout << "Please enter the faculty's department: " << endl;
            cin >> department;
            cout << "Please enter the faculty's advisee's ID numbers, each seperated by a comma (enter 'none' if faculty does not have any advisees): " << endl;
            cin >> listOfAdvisees;
            //Using a stringstream to add a list of advisees to the faculty's advisee list
            stringstream ss(listOfAdvisees);
            int i;
            if (listOfAdvisees == "none"){
                cout << "No advisees added." << endl;
            }else{
                //loop that adds each advisee to the list, seperated by a comma
                while (ss >> i)
                {
                    adviseeList->addFront(i);
                    if (ss.peek() == ',')
                        ss.ignore();
                }
            }
            //Add the faculty to the tree
            Faculty faculty(facultyID, name, level, department, adviseeList);
            dataBase->addFacultyToTree(faculty);
            
            cout << "Successfully added faculty member." << endl;

            //After adding a faculty member, check if the tree is balanced, if not rebalance the tree
            if(dataBase->getFacultyTree()->isTreeBalanced() != true){
                dataBase->reblanceFacultyTree();
            }
        }
        else if(option == 8){
            //Delete a faculty member given the id
            cout << "Please enter the faculty's ID number: " << endl;
            int facultyID;
            cin >> facultyID;
            dataBase->deleteFaculty(facultyID);
            cout << "Successfully deleted faculty member." << endl;

            //After deleting a faculty member, check if the tree is balanced, if not rebalance the tree
            if(dataBase->getFacultyTree()->isTreeBalanced() != true){
                dataBase->reblanceFacultyTree();
            }
        }
        else if(option == 9){
            //Change a student’s advisor given the student id and the new faculty id
            int studentID;
            int facultyID;
            cout << "Please enter the student's ID number: " << endl;
            cin >> studentID;
            cout << "Please enter the NEW faculty's ID number: " << endl;
            cin >> facultyID;
            dataBase->changeAdvisor(studentID, facultyID);
            cout << "Successfully changed student's advisor." << endl;
        }
        else if(option == 10){
            //Remove an advisee from a faculty member given the ids
            int studentID;
            int facultyID;
            cout << "Please enter the student's ID number: " << endl;
            cin >> studentID;
            cout << "Please enter the faculty's ID number: " << endl;
            cin >> facultyID;
            dataBase->removeAdvisee(facultyID, studentID);
            cout << "Successfully removed advisee from faculty member." << endl;
        }
        else if(option == 11){
            //Exit
            exit = true;
        }
        else{
            cout << "Invalid option. Please try again." << endl;
            exit = true;
        }
    }


    //Open an output file
    ofstream outputFile;
    outputFile.open("runLog.txt");
    //More info in README regarding this implementation
    //Basically redirects cout so we can use printAllStudents and printAllFaculty to print to the file
    streambuf* originalCoutStreamBuffer = cout.rdbuf();
    cout.rdbuf(outputFile.rdbuf());

    stringstream studentOutput;
    stringstream facultyOutput;

    //Redirect cout to the stringstream studentOutput
    cout.rdbuf(studentOutput.rdbuf());
    //Print all students to the stringstream
    dataBase->printAllStudents();
    //Redirect cout to the stringstream facultyOutput
    cout.rdbuf(facultyOutput.rdbuf());
    //Print all faculty to the stringstream
    dataBase->printAllFaculty();

    outputFile << "----STUDENTS----" << endl;
    outputFile << studentOutput.str() << endl;
    outputFile << endl;
    outputFile << "----FACULTY----" << endl;
    outputFile << facultyOutput.str() << endl;

    //redirect cout back to the console
    cout.rdbuf(originalCoutStreamBuffer);
    //Close the file
    outputFile.close();
    
    //Delete the database object
    delete dataBase;
    return 0;
}