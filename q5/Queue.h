#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    T *queue;
    int size;
    int capacity;
    void check();
public:
    Queue();
    ~Queue();
    void enqueue(const T &element);
    void dequeue();
    T getFront();
    void printQueue();
};

template <typename T>
Queue<T>::Queue() : size(0), capacity(10){
    queue = new T[capacity];
}

template <typename T>
Queue<T>::~Queue(){
    delete[] queue;
}

template <typename T>
void Queue<T>::enqueue(const T &element){
    if(size == capacity){
        T *temp = new T[capacity * 2];
        for(int i = 0; i < size; i++){
            temp[i] = queue[i];
        }

        delete[] queue;
        queue = temp;
        capacity = capacity * 2;
    }

    queue[size] = element;
    size++;
}

template <typename T>
void Queue<T>::dequeue(){
    check();
    for(int i = 0; i < size - 1; i++){
        queue[i] = queue[i + 1];
    }

    size--;
}

template <typename T>
void Queue<T>::check(){
    if(size == 0){
        throw std::out_of_range("Nothing to remove.");
    }
}

template <typename T>
T Queue<T>::getFront(){
    check();
    return queue[0];
}

template <typename T>
void Queue<T>::printQueue() {
    for (int i = 0; i < size; i++) {
        std::cout << queue[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl; 
}


#endif /* QUEUE_H */