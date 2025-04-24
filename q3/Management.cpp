#include <iostream>
#include <algorithm>
#include "Management.h"

using namespace std;


Employee::Employee(): name(""), position(""), salary(0.0){}

string Employee::getName(){
    return name;
}

void Employee::setName(string n){
    name = n;
}

string Employee::getPosition(){
    return position;
}

void Employee::setPosition(string p){
    position = p;
}

double Employee::getSalary(){
    return salary;
}

void Employee::setSalary(double s){
    salary = s;
}


int Manager::getTeamSize(){
    return teamSize;
}

void Manager::setTeamSize(int t){
    teamSize = t;
}

double Manager::calculateBonus(){
    double bonus;
    double salary = getSalary();
    double teamBonus = 0;

    teamBonus = 1.0/20 * salary * teamSize;

    bonus = 1.0/10 * salary + teamBonus;

    return bonus;
}


string Developer::getProgrammingLanguage(){
    return programmingLanguage;
}

void Developer::setProgrammingLanguage(string pl){
    programmingLanguage = pl;
}

double Developer::calculateBonus() {
    double bonus;
    double salary = getSalary();

    if(programmingLanguage == "Java"){
        return bonus = 3.0/20 * salary;
    } else {
        return bonus = 1.0/10 * salary;
    }
}
