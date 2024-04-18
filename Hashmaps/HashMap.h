#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <string>
#include <limits>
#include <stdexcept>
using namespace std;

struct KeyValuePair{
  KeyValuePair();
  KeyValuePair(int k, string v);
  KeyValuePair(const KeyValuePair& kv);
  virtual ~KeyValuePair();
  int m_key;
  string m_value;
};

class HashMap{
public:
  HashMap();
  virtual ~HashMap();
  void put(int key, string value);
  string get(int key);
  string remove(int key);
  int size();
  bool contains(int key);
private:
  KeyValuePair* m_array;
  int m_size;
  int m_max_elements;
  const static double LOAD_FACTOR;
  int hashKey(int key);
  int containsHelper(int key);
  void resizeIfNeeded();

};


#endif
