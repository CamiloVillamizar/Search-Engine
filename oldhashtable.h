//#ifndef HASHTABLE_H
//#define HASHTABLE_H
//#include <iostream>
//#include <string>
//#include <vector>
//#include <functional>
//using namespace std;

//template <typename K, typename V>
//class hashNode
//{
//    private:
//          K key;
//          V value;
//          hashNode * next;
//    public:
//          hashNode()
//          {
//              next = nullptr;
//          }

//          hashNode<K,V>& operator= (const hashNode<K,V>* second)
//          {
//              key = second->key;
//              value = second->value;
//              next = second->next;
//              return *this;
//          }

//          hashNode(K keys, V values)
//          {
//              key = keys;
//              value = values;
//              next = nullptr;
//          }

//          hashNode(const hashNode<K,V>& second)
//          {
//              key = second.key;
//              value = second.value;
//              next = second.next;
//          }

//          bool operator== (const hashNode<K,V>* secondKey)
//          {
//              if(key == secondKey->key && value == secondKey->value)
//                  return true;
//              else
//                  return false;
//          }

//          bool operator != (const hashNode<K,V>* secondKey)
//          {
//              if(key == secondKey->key && value == secondKey->value)
//                  return false;
//              else
//                  return true;
//          }

//          void setNext(hashNode<K,V>* nxt)
//          {
//              this->next = nxt;
//          }

//          hashNode<K, V>* getNext()
//          {
//              return next;

//          }

//          void setKey(K key)
//          {
//              this->key = key;
//          }

//          K getKey()
//          {
//                return key;
//          }

//          void setValue(V val)
//          {
//              this->value = val;
//          }

//          V getValue()
//          {
//                return value;
//          }
//          V* getValPtr()
//          {
//              return &value;
//          }

//          ~hashNode<K, V>(){
//              delete[] next;
//          }
//};

//template <typename K, typename V>
//class hashTable
//{
//    private:
//          hashNode<K,V> *table;
//          int capacity;
//          int size;
//    public:
//          hashTable();
//          hashTable(const hashTable<K,V> &);
//          hashTable<K,V>& operator= (const hashTable<K,V>*);
//          vector<V> search(K);
//          void insert(K&,V&);
//          ~hashTable();
//          int getSize();
//          void display();
//          void printIndex(ofstream&);
//};

//template <typename K, typename V>
//hashTable<K,V>::hashTable()
//{
//    table = new hashNode<K, V>*[capacity];
//    for (int i = 0; i < capacity; i++)
//        table[i].setNext(nullptr);


////    capacity = 300000;
////    size = 0;
////    table = new hashNode<K,V>[capacity];
////    for (int i = 0; i < capacity; i++)
////            table[i] = new hashNode<K, V>();
//}

//template<typename K, typename V>
//hashTable<K,V>::hashTable(const hashTable<K, V> & second)
//{
//    for(int i = 0; i < capacity; i++)
//    {
//        table[i] = second->table[i];
//    }
//}

//template <typename K, typename V>
//hashTable<K,V>& hashTable<K,V>::operator= (const hashTable<K,V>* second)
//{
//    for(int i = 0; i < capacity; i++)
//    {
//        table[i] = second->table[i];
//    }
//    return *this;
//}

//template <typename K, typename V>
//void hashTable<K,V>::insert(K& key, V& value)
//{
//    string key2 (key);
//    hash<string> str_hash;
//    size_t hashInd = str_hash(key2) % capacity;

//    hashNode<K, V> *temp = &table[hashInd];

//    if(table[hashInd].getKey() == "")
//    {
//        table[hashInd] = new hashNode<K,V>(key, value);
//        size++;
//    }
//    else
//    {
//        while(temp->getNext() != nullptr)
//        {
//            temp = temp->getNext();
//        }
//        temp->setNext(new hashNode<K,V>(key, value));
//    }
//}

//template <typename K, typename V>
//int hashTable<K,V>::getSize()
//{
//    return size;
//}

//template <typename K, typename V>
//void hashTable<K,V>::display()
//{
//    for(int i = 0; i < capacity ; i++)
//    {
//        hashNode<K, V> *temp = &table[i];
//        if(table[i].getKey() != "")
//        {
//            cout << "key = " << table[i].getKey();
//            cout << " value = " << temp->getValue()->getCode() << endl;
//            while(temp->getNext() != nullptr)
//            {
//                temp = temp->getNext();
//                cout << " value = " << temp->getValue()->getCode() << endl;

//            }
//        }
//    }
//}


//template <typename K, typename V>
//void hashTable<K, V>::printIndex(ofstream& outFile){
////    for(int i = 0; i < capacity ; i++)
////    {
////        hashNode<K, V> *temp = &table[i];
////        if(table[i].getKey() != "")
////        {
////            outFile << "key = " << table[i].getKey();
////            outFile << " value = " << temp->getValue()->getCode() << endl;
////            while(temp->getNext() != nullptr)
////            {
////                temp = temp->getNext();
////                outFile << " value = " << temp->getValue()->getCode() << endl;

////            }
////        }
////    }
//}

//template <typename K, typename V>
//vector<V> hashTable<K,V>::search(K item)
//{
//    vector<V> items;
//    string key2 (item);
//    hash<string> str_hash;
//    size_t hashInd = str_hash(key2) % capacity;
//    hashNode<K,V> temp = table[hashInd];
//    if(temp.getKey() == item)
//    {
//        items.push_back(temp.getValue());
//        while(temp.getNext()!=nullptr)
//        {
//            temp = temp.getNext();
//            items.push_back(temp.getValue());
//        }
//    }
//    return items;
//}

//template <typename K, typename V>
//hashTable<K,V>::~hashTable()
//{
//      for(int i = 0; i < capacity; i++)
//      {
//          delete &table[i];
//          table[i].setNext(nullptr);
//      }
//}

//#endif
