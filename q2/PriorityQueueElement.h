#ifndef PRIORITYQUEUEELEMENT_H
#define PRIORITYQUEUEELEMENT_H
#include <iostream>

class PriorityQueueElement{ 
private:
    std::string elementValue;
    int elementPriority;

public:
    PriorityQueueElement(std::string value); //defualt value in implementation
    PriorityQueueElement(std::string value, int priority);
    std::string getValue() const;
    int getPriority() const;
    void setPriority(int priority);
};

#endif /* PRIORITYQUEUELEMENT_H */