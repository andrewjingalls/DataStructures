#include "HashMap.h"


KeyValuePair::KeyValuePair(){
  m_key = numeric_limits<int>::min(); //set all keys to minimum int value by default
}

KeyValuePair::KeyValuePair(int k, string v){
  m_key = k;
  m_value = v;
}

KeyValuePair::KeyValuePair(const KeyValuePair& kv){
  m_key = kv.m_key;
  m_value = kv.m_value;
}

KeyValuePair::~KeyValuePair(){

}

const double HashMap::LOAD_FACTOR = 0.70;

HashMap::HashMap(){
  m_max_elements = 100;
  m_array = new KeyValuePair[100];
  m_size = 0;
}

HashMap::~HashMap(){
  delete[] m_array;
}

void HashMap::put(int key, string value){
  KeyValuePair kv(key,value);
  int idx = hashKey(key);
  //if they key exists, replace the mapping. Or find the first empty bucket
  while(m_array[idx].m_key != key && m_array[idx].m_key != numeric_limits<int>::min()){
    ++idx;
  }
  m_array[idx] = kv;
  ++m_size;
  resizeIfNeeded();

}

string HashMap::get(int key){
  int idx = containsHelper(key);
  if(idx < 0){
    throw std::invalid_argument("Key is not in map");
  }
  return m_array[idx].m_value;
}

int HashMap::containsHelper(int key){
  int ret = -1;
  int idx = hashKey(key);
  for(int i = idx; i < m_max_elements; ++i){ //probe
    if(m_array[i].m_key == key){
      ret = i;
      break;
    }
  }
  return ret;
}

string HashMap::remove(int key){
  int idx = containsHelper(key);
  if(idx < 0){
    throw std::invalid_argument("Key is not in map");
  }
  string ret = m_array[idx].m_value;
  KeyValuePair emptyKV;
  m_array[idx] = emptyKV;
  --m_size;
  return ret;
}

int HashMap::size(){
  return m_size;
}

bool HashMap::contains(int key){
  if(containsHelper(key) < 0){
    return false;
  } else{
    return true;
  }
}

int HashMap::hashKey(int key){
  return key%m_max_elements;
}

void HashMap::resizeIfNeeded(){
  double currentLF = (double)m_size/(double)m_max_elements;
  if(currentLF > LOAD_FACTOR){
    int oldMax = m_max_elements;
    m_max_elements *= 2;
    KeyValuePair* oldArr = m_array;
    m_array = new KeyValuePair[m_max_elements]; //resize
    for(int i = 0; i < oldMax; ++i){ //rehash
      if(oldArr[i].m_key != numeric_limits<int>::min()){
        put(oldArr[i].m_key,oldArr[i].m_value);
      }
    }
    delete[] oldArr;
  }
}
