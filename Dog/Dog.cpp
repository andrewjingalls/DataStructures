#include "Dog.h"
#include <cstdlib>  //includes several general purpose functions including dynamic memory management, random number generation, etc.

Dog::Dog(){
    m_name = "";
    m_age = 0;
    m_owner = NULL;
}

Dog::Dog(string name, int age, string OwnerName){
    m_name = name;
    m_age = age;
    m_owner = new Person(OwnerName); //initialize pointer
}

Dog::~Dog(){
    if(m_owner != NULL){
        delete m_owner;
    }
}

void Dog::speak(){
    cout << "I'm a dog. My name is " <<m_name<< endl;
    cout << "I've been alive for " <<m_age<< " years." <<endl;
    cout << "I belong to " << m_owner->getName() << endl; //accessing the name of the owner instead of dog
}

string Dog::getName(){
    return m_name;
}
void Dog::setName(string name){
    m_name = name;
}

int Dog::getAge(){
    return m_age;
}
void Dog::setAge(int age){
    m_age = age;
}

