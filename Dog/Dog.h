#ifndef DOG_H
#define DOG_H

#include "Person.h"
#include <iostream>     //defines standard input/output operations
using namespace std;

class Dog{
    public:
        Dog();
        Dog(string name, int age, string ownerName);
        virtual ~Dog();
        void speak();
        string getName();
        int getAge();
        void setName(string name);
        void setAge(int age);

    private:
        string m_name;
        int m_age;
        Person* m_owner;   //declares a pointer variable to a Person object
};

#endif