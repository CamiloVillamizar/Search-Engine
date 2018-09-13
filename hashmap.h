#ifndef HASHMAP_H
#define HASHMAP_H
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

template <typename K, typename V>
class mapNode
{
    private:
          K key;
          V value;
    public:
          mapNode()
          {
          }

          mapNode<K,V>& operator= (const mapNode<K,V>* second)
          {
              key = second->key;
              value = second->value;
          }

          bool operator== (const mapNode<K,V>* secondKey)
          {
              if(key == secondKey->key && value == secondKey->value)
                  return true;
              else
                  return false;
          }

          bool operator != (const mapNode<K,V>* secondKey)
          {
              if(key == secondKey->key && value == secondKey->value)
                  return false;
              else
                  return true;
          }

          mapNode(K key, V value)
          {
              this->key = key;
              this->value = value;
          }

          void setKey(K key)
          {
              this->key = key;
          }

          K getKey()
          {
                return key;
          }

          void setValue(V val)
          {
              this->value = val;
          }

          V getValue()
          {
                return value;
          }

          V* getValuePtr(){
              return &value;
          }
};

template <typename K, typename V>
class hashMap
{
    private:
          mapNode<K,V> *table;
          int capacity;
          int size;
    public:
          hashMap();
          hashMap<K,V>& operator= (const hashMap<K,V>&);
          V get(K);
          V search(K);
          void insert(K,V);
          ~hashMap();
          int getSize();
          void display();
          void display(ofstream&);
          void bringBack(ifstream&);

};

template <typename K, typename V>
hashMap<K,V>::hashMap()
{
    capacity = 200000;
    size = 0;
    table = new mapNode<K,V>[capacity];
    for (int i = 0; i < capacity; i++)
            table[i] = new mapNode<K, V>();
}

template <typename K, typename V>
hashMap<K,V>& hashMap<K,V>::operator= (const hashMap<K,V>& second)
{
    for(int i = 0; i < capacity; i++)
    {
        table[i] = second.table[i];
    }
    return *this;
}

template <typename K, typename V>
V hashMap<K,V>::get(K key)
{
    string key2 (key);
    hash<string> str_hash;
    size_t hashInd = str_hash(key2) % capacity;
    return table[hashInd].getValue();
}

template <typename K, typename V>
void hashMap<K,V>::insert(K key, V value)
{
    string key2 (key);
    hash<string> str_hash;
    size_t hashInd = str_hash(key2) % capacity;
    if(table[hashInd].getKey() == key)
    {
        table[hashInd].getValuePtr()->pushback(value.getPtr());
    }
    else
    {
        table[hashInd].setKey(key);
        table[hashInd].setValue(value);
        size++;
    }
}

template <typename K, typename V>
int hashMap<K,V>::getSize()
{
    return size;
}

template <typename K, typename V>
void hashMap<K,V>::display()
{
    for(int i = 0; i < capacity ; i++)
    {
        K one = table[i].getKey();
        if(table[i].getKey() != "")
        {
            cout << "key = " << table[i].getKey()
                 <<"  value = "<< table[i].getValue() << endl;
        }
    }
}

template <typename K, typename V>
V hashMap<K,V>::search(K item)
{
    string key2 (item);
    hash<std::string> str_hash;
    size_t hashInd = str_hash(key2) % capacity;
        if(table[hashInd].getKey() == item)
            return table[hashInd].getValue();
    cout << "\033[1;31mNO RESULTS FOUND\033[0m\n" << endl;
}

template <typename K, typename V>
void hashMap<K,V>::display(ofstream& outFile){
    vector<question*> allQuests;

    for(int i = 0; i < capacity ; i++)
    {
        if(table[i].getKey() != "")
        {
            vector<question*> temp = table[i].getValue().getVect();
            for(int j = 0; j < temp.size(); j++){
                allQuests.push_back(temp.at(j));
            }
        }
    }

    vector<question*>::iterator it = unique(allQuests.begin(), allQuests.end());
    allQuests.resize(distance(allQuests.begin(), it));

    for(int i = 0; i < allQuests.size(); i++)
    {
        outFile << *allQuests[i] << endl;
    }
}

template <typename K, typename V>
void hashMap<K,V>::bringBack(ifstream& str)
{

}

#endif
