#ifndef PRIORITYQUEUE_H 
#define PRIORITYQUEUE_H

#include <iostream>
#include "PriorityQueueElement.h"

class PriorityQueue{
private:
    int capacity;
    int size;
    PriorityQueueElement **heap;
    void bubbleUp(int i);
    void bubbleDown(int i);
    void checkCapacity();
public:
    PriorityQueue();
    ~PriorityQueue();
    void put(std::string value, int priority);
    std::string pop();
};

#endif /* PRIORITYQUEUE_H */