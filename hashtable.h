#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

template <typename K, typename V>
class hashNode
{
    private:
          K key;
          V value;
          hashNode* next;
    public:
          hashNode()
          {
              next = nullptr;
          }

          hashNode<K,V>& operator= (const hashNode<K,V>* second)
          {
              key = second->key;
              value = second->value;
              next = second->next;
              return *this;
          }

          hashNode(K keys, V values)
          {
              key = keys;
              value = values;
              next = nullptr;
          }

          hashNode(const hashNode<K,V>& second)
          {
              key = second.key;
              value = second.value;
              next = second.next;
          }

          bool operator== (const hashNode<K,V>* secondKey)
          {
              if(key == secondKey->key && value == secondKey->value)
                  return true;
              else
                  return false;
          }

          bool operator != (const hashNode<K,V>* secondKey)
          {
              if(key == secondKey->key && value == secondKey->value)
                  return false;
              else
                  return true;
          }

          void setNext(hashNode<K,V>* nxt)
          {
              this->next = nxt;
          }

          hashNode<K, V>* getNext()
          {
              return next;

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
          V* getValPtr()
          {
              return &value;
          }

          void clrNext(){
              next = nullptr;
          }

          ~hashNode<K, V>(){
              //delete[] next;
          }
};

template <typename K, typename V>
class hashTable
{
    private:
          hashNode<K,V>** table;
          int capacity;
          int size;
    public:
          hashTable();
          hashTable(const hashTable<K,V>&);
          hashTable<K,V>& operator=(const hashTable<K,V>*);
          vector<V> search(K);
          void insert(K&,V&);
          int getSize();
          void display();
          void display(ofstream&);
          void bringBack(ifstream&);
          //~hashTable();
};

template <typename K, typename V>
hashTable<K,V>::hashTable()
{
    capacity = 300000;
    size = 0;
    table = new hashNode<K, V>* [capacity];
    for(int i = 0; i < capacity; i++)
    {
        table[i] = nullptr;
    }
}

//template <typename K, typename V>
//hashTable<K,V>::~hashTable()
//{
//    for(int i = 0; i < capacity; i++)
//    {
//        for(hashNode<K,V>* cur = table[i]; ; ){
//            hashNode<K,V>* temp = cur->getNext();
//            delete cur;
//            cur = temp;
//            if(cur == nullptr) break;
//        }
//        /*while(table[i]->getNext() != nullptr)
//        {
//            delete table[i]->getNext();
//            table[i]->setNext(table[i]->getNext());
//        }*/
//    }
//    delete table;
//}

template<typename K, typename V>
hashTable<K,V>::hashTable(const hashTable<K, V> & second)
{
//    for(int i = 0; i < capacity; i++)
//    {
//        table[i] = second->table[i];
//    }
}

template <typename K, typename V>
hashTable<K,V>& hashTable<K,V>::operator= (const hashTable<K,V>* second)
{
//    for(int i = 0; i < capacity; i++)
//    {
//        table[i] = second->table[i];
//    }
//    return *this;
}

template <typename K, typename V>
void hashTable<K,V>::insert(K& key, V& value)
{
    hash<string> str_hash;
    size_t hashInd = str_hash(key) % capacity;

    hashNode<K,V>* newInsert = new hashNode<K, V>(key, value);
    newInsert->setNext(nullptr);
    if(table[hashInd] == nullptr){
        table[hashInd] = newInsert;
        size++;
    } else {
        hashNode<K, V> *current = table[hashInd];
        while(current->getNext() != nullptr){
            current = current->getNext();
        }
        current->setNext(newInsert);
    }
}

template <typename K, typename V>
int hashTable<K,V>::getSize()
{
    return size;
}

template <typename K, typename V>
void hashTable<K,V>::display()
{
    for(int i = 0; i < capacity ; i++)
    {
        if(table[i] != nullptr){
            hashNode<K, V> *temp = table[i];
            cout << temp->getKey() << endl;
            if(temp->getKey() != "")
            {
                cout << *table[i]->getValue();
                while(temp->getNext() != nullptr)
                {
                    temp = temp->getNext();
                    cout << *temp->getValue();

                }
            }
        }
    }
}

template <typename K, typename V>
vector<V> hashTable<K,V>::search(K item)
{
    string item2 (item);
    hash<string> str_hash;
    size_t hashInd = str_hash(item2) % capacity;

    vector<V> rVect;

    if(table[hashInd] == nullptr){

    } else {
        hashNode<K, V>* current = table[hashInd];
        while(current->getNext() != nullptr){
            rVect.push_back(current->getValue());
            current = current->getNext();
        }
        rVect.push_back(current->getValue());
    }
    return rVect;
}

template <typename K, typename V>
void hashTable<K, V>::display(ofstream& outFile){
    for(int i = 0; i < capacity ; i++)
    {
        if(table[i] != nullptr){
            hashNode<K, V> *temp = table[i];
            if(temp->getKey() != "")
            {
                outFile << *table[i]->getValue();
                while(temp->getNext() != nullptr)
                {
                    temp = temp->getNext();
                    outFile << *temp->getValue();
                }
            }
        }
    }
}

template <typename K, typename V>
void hashTable<K,V>::bringBack(ifstream& str)
{

}

#endif
