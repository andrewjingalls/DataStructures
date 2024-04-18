//Command line args

#include <iostream>
using namespace std;   

/*
argc - argument count - stores number of command line arguments passed
    by the user including the name of the program

argv - argument vector - an array of character pointers listing all the arguments
    - argv[0] = the name of the program
*/

int main(int argc, char** argv){

    cout<< "You have entered " << argc << " arguments" << end;;
    for (int i = 0; i < argc; ++i){
        cout << "arg " << i << ": " << argv[i] << endl;
    }




    return 0;
}