#include "Dog.h"

int main(){
    Dog d1("Macie", 6, "Andrew"); //creating object on stack, statically allocated, allocated at compile time
    Dog* d2 = new Dog("Lilah", 3, "Stevens"); //creating object on heap, dynamically allocated, allocated at runtime

    d1.speak();
    d2->speak();

    delete d2;

    return 0;
}