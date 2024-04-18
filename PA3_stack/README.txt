/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA3: Do You See What I See?

Source Files:
MonoStack.h
SpeakerView.h
SpeakerView.cpp
main.cpp
sample.txt

No compile/runtime errors

I went to the TLC to help me understand how to push the items in the stack in monotonically
increasing or decreasing order. I spent a lot of time struggling and stressing about getting
it perfect, but honestly, I ended up short. I was able read in the file and push each column
into a stack, but the struggles came when trying to make sure they were in the correct order. 
I knew I needed to store the values in a temp stack, but I was having trouble figuring out how.
I tried for plenty of hours but would end up with countless segmentation faults.
The program runs, and the output is close, but not perfect.

TO COMPILE:
g++ -o main *.cpp

TO RUN:
./main
Enter name of the input file: sample.txt
*/