#include "Queue.h"
#include <iostream>

int main(){
    Queue<int> intQueue;

    intQueue.enqueue(10);
    intQueue.enqueue(9);
    intQueue.enqueue(15);
    intQueue.enqueue(1);
    intQueue.enqueue(21);
    intQueue.printQueue();
    intQueue.dequeue();
    intQueue.printQueue();
    std::cout << intQueue.getFront() << std::endl;

    Queue<std::string> stringQueue;

    stringQueue.enqueue("Fi");
    stringQueue.enqueue("Fu");
    stringQueue.enqueue("Fa");
    stringQueue.enqueue("Fo");
    stringQueue.printQueue();
    stringQueue.dequeue();
    stringQueue.printQueue();
    std::cout << stringQueue.getFront() << std::endl;


    return 0;
}