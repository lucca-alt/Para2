#include <iostream>
#include "PriorityQueueElement.h"

PriorityQueueElement::PriorityQueueElement(std::string e)
    : elementValue(e), elementPriority(1){} //trying out initializer lists

PriorityQueueElement::PriorityQueueElement(std::string e, int p)
    : elementValue(e), elementPriority(p){}

std::string PriorityQueueElement::getValue() const {
    return elementValue;
}

int PriorityQueueElement::getPriority() const {
    return elementPriority;
}

void PriorityQueueElement::setPriority(int priority){
    elementPriority = priority;
}
