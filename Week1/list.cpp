#include <iostream>
using namespace std;
const int Max = 1000;
struct List{
    int size;
    int arr[Max];
    List(){
        size = 0;
    }
    int get(int i){
        return arr[i];
    }
    void addFirst(int data){
        for(int i = size; i > 0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = data;
        size++;
    }
    void addLast (int data){
        arr[size] = data;
        size++;
    }
    void insert(int data, int pos){
        if (pos < 0 || pos > size) return;
        for (int i = size; i > pos; i--){
            arr[i]= arr[i-1];
        }
        arr[pos] = data;
        size++;
    } .
    void deleteFirst(){
        if (size == 0) return;
        for (int i = 0; i < size - 1; i++){
            arr[i] = arr[i+1];
        }
        size--;
    }
    void deleteLast(){
        if (size == 0) return;
        size--;
    }
    void remove(int pos){
        if (size == 0) return;
        if (pos < 0 || pos >= size) return;
        for (int i = pos; i < size-1; i++){
            arr[i] = arr[i+1];
        }
        size--;
    }
    void traverseForward(){
        for(int i=0; i <= size-1;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void traverseBackward(){
        for(int i=size-1; i >= 0;i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

