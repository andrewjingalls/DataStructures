#include "HashMap.h"
#include <iostream>
using namespace std;

int main(){
  HashMap hm;
  hm.put(1,"Stevens");
  hm.put(237,"Linstead");
  hm.put(315,"German");
  cout << hm.contains(237) << endl;
  cout << hm.get(315) << endl;
  cout << hm.remove(1) << endl;
  cout << hm.contains(1) << endl;
  cout << hm.size() << endl;
}
