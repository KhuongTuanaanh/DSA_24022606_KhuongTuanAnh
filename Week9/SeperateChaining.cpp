#include<bits/stdc++.h>
using namespace std;
#define SIZE 20
struct Node{
    int key;
    int data;
    Node* next;
};
Node* hashTable[SIZE] = {nullptr};
int hashCode(int key){
    return key% SIZE;
}
Node* search(int key){
    int index = hashCode(key);
    Node* temp = hashTable[index];
    while (temp != nullptr) {
        if (temp->key == key)
            return temp;
        temp = temp->next;
    }

    return nullptr;
}
