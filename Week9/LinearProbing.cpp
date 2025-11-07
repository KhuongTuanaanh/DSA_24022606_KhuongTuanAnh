#include<bits/stdc++.h>
using namespace std;
#define SIZE 20
struct Data{
    int data;
    int key;
};
Data* hasharray[SIZE];
Data* a;
int hashCode(int key){
    return key % SIZE;
}
Data* search(int key) {
    int hashIndex = hashCode(key);
    while(hasharray[hashIndex] != nullptr){
        if(hasharray[hashIndex]->key == key)
            return hasharray[hashIndex];
        ++hashIndex;
        hashIndex %= SIZE;
    }
    return nullptr;
}
void insert(int key, int data){
    auto* item = new Data{key,data};
    int hashIndex = hashCode(key);
    while(hasharray[hashIndex] != nullptr && hasharray[hashIndex]->key != -1){
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hasharray[hashIndex] = item;
}
void deleteItem(Data* item){
    int key = item->key;
    int hashIndex = hashCode(key);
    while(hasharray[hashIndex] != nullptr){
        if(hasharray[hashIndex]->key == key){
            Data* temp= hasharray[hashIndex];
            hasharray[hashIndex] = a;
            return temp;
        }
        ++hashIndex;
        hashIndex %= SIZE;
    }
    return nullptr;
}
