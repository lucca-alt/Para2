#include <iostream>
#include "PriorityQueue.h"
#include "PriorityQueueElement.h"


int main(){
    PriorityQueue pq;
    pq.put("LowPriorityTask", 1);
    pq.put("MediumPriorityTask", 5);
    pq.put("CriticalBugFix", 10);
    pq.put("ImportantEmail", 7);
    pq.put("VeryImportantEmail", 8);
    pq.put("RoutineCheck", 2);
    pq.put("ExtinctionEvent", 99);
    
    for(int i = 0; i < 7; i++){
        std::cout << pq.pop() << std::endl;
    }
}