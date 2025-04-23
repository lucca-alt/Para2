#include <iostream>
#include "PriorityQueue.h"
#include "PriorityQueueElement.h"

PriorityQueue::PriorityQueue()
    : size(0), capacity(1){
        heap = new PriorityQueueElement*[capacity]; //stores capacity(1) amount of pointers to PriorityQueueElement objects
                                                    //because there is no standard constructor
    }

PriorityQueue::~PriorityQueue(){
    for(int i = 0; i < size; i++){
        delete heap[i];
    }
    delete[] heap;
    heap = nullptr;
}

void PriorityQueue::bubbleUp(int i){

    while(i > 0 && heap[i]->getPriority() > heap[(i - 1) / 2]->getPriority()){ //compare node to parent and swap if greater
        int parentIndex = (i - 1) / 2;
        PriorityQueueElement *temp = heap[i];
        heap[i] = heap[parentIndex];
        heap[parentIndex] = temp;

        i = parentIndex;
    }
}

void PriorityQueue::bubbleDown(int i){
    // if there is left child
    while (2 * i + 1 < size) { 
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = leftChild;

        //check if rightChild is greater than leftChild
        if (rightChild < size && heap[rightChild]->getPriority() > heap[leftChild]->getPriority()) {
            largest = rightChild;
        }

        // check if largest child is actually bigger than the node
        if (heap[largest]->getPriority() > heap[i]->getPriority()) { // swap and move down
            PriorityQueueElement* temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            i = largest; 
        } else {
            break; //break in case the condition is satisfied
        }
    }
}

void PriorityQueue::checkCapacity(){ 
    if(size >= capacity){ //double the capacity if size >= to capacity
        int increasedCapacity = capacity * 2;
        PriorityQueueElement **newHeap = new PriorityQueueElement*[increasedCapacity]; 

        for(int i = 0; i < capacity; i++){
            newHeap[i] = heap[i];
        }

        delete[] heap;
        heap = newHeap;
        capacity = increasedCapacity;
    }

    if(size <= capacity / 4 && capacity > 1){ //shrink if its greatly underused
        int decreasedCapacity = capacity / 2;
        PriorityQueueElement **newHeap = new PriorityQueueElement*[decreasedCapacity];

        for(int i = 0; i < decreasedCapacity; i++){
            newHeap[i] = heap[i];
        }

        delete[] heap;
        heap = newHeap;
        capacity = decreasedCapacity;
    }

    std::cout << capacity << std::endl; //checking for dynamically adjusted heap
}

void PriorityQueue::put(std::string value, int priority){
    checkCapacity();

    heap[size] = new PriorityQueueElement(value, priority);
    bubbleUp(size);
    size++;

}

std::string PriorityQueue::pop(){
    if(size == 0){
        return "Heap is Empty";
        }

    std::string value0 = heap[0]->getValue(); //save value at root to return
    delete heap[0];
    heap[0] = heap[size-1]; //move last element in heap to root
    size--;
    bubbleDown(0); //fit the last element into right spot

    checkCapacity();

    return value0;
}
