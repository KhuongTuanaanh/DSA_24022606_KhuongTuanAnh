#include <iostream>
#include "list.cpp"
using namespace std;
struct priorityQueue {
    List heap;
    void swap(int i, int j){
        int temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }
    void swim(int k){
        while (k > 0 && heap.get(((k - 1) / 2)) < heap.get(k)){
            swap(k, ((k - 1) / 2));
            k = (k-1)/2;
        }
    }
    void sink(int k){
        while (2*k+1 < heap.getSize()) {
            int j = 2*k+1;
            if (j + 1 < heap.getSize() && heap.get(j) < heap.get(j+1)) {
                j++;
            }
            if (heap.get(k) >= heap.get(j)) {
                break;
            }
            swap(k,j);
            k= j;
        }
    }

    void insert(int data){
        heap.addLast(data);
        swim(heap.getSize() - 1);
    }

    int delMax(){
        if (isEmpty()){
            cout << "Heap nay rong!" << endl;
        }
        int temp = heap.get(0);
        swap(0, heap.getSize() - 1);
        heap.deleteLast();
        sink(0);
        return temp;
    }

    bool isEmpty(){
        if (heap.getSize() == 0){
            return true;
        }
        return false;
    }

    int max(){
        int Max;
        if (isEmpty()){
            cout << "Heap nay rong!" << endl;
        }
        else {
            Max = heap.get(0);
        }
        return Max;
    }

    int size(){
        return heap.getSize();
    }

    void printHeap(){
        for (int i = 0; i < heap.getSize(); i++){
            cout << heap.get(i) << " ";
        }
        cout << endl;
    }
};
