#include <iostream>
#include "Management.h"

using namespace std;

int main(){
    Manager m;
    m.setName("Yi Lon Mah");
    m.setPosition("Manager");
    m.setSalary(5000.0);
    m.setTeamSize(4);

    Developer d;
    d.setName("Piccolo");
    d.setPosition("Developer");
    d.setSalary(3500.0);
    d.setProgrammingLanguage("Java");

    cout << "The bonus for " << m.getName() << " is " << m.calculateBonus() << endl;
    cout << "The bonus for " << d.getName() << " is " << d.calculateBonus() << endl;
    return 0;
}