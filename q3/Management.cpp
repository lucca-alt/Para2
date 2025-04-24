#include <iostream>
#include <algorithm>

using namespace std;

class Employee {
private:
    string name;
    string position;
    double salary;

public:
    Employee(string name, string position, double salary)
        : name(name), position(position), salary(salary){}

    string getName(){
        return name;
    }

    void setName(string n){
        name = n;
    }

    string getPosition(){
        return position;
    }

    void setPosition(string p){
        position = p;
    }

    double getSalary(){
        return salary;
    }

    void setSalary(double s){
        salary = s;
    }

    virtual double calculateBonus() = 0;
};

class Manager : public Employee{
private: 
    int teamSize;

public:
    int getTeamSize(){
        return teamSize;
    }

    void setTeamSize(int t){
        teamSize = t;
    }

    double calculateBonus(double salary, int teamSize){
        double bonus;
        double teamBonus = 0;

        for(int i = 0; i <=teamSize; i++){
            teamBonus += 1/20 * salary;
        }

        bonus = 1/10 * salary + teamBonus;

        return bonus;
    }
};

class Developer : public Employee{
private:
    string programmingLanguage;

public:
    string getProgrammingLanguage(){
        return programmingLanguage;
    }

    void setProgrammingLanguage(string pl){
        programmingLanguage = pl;
    }

    double calculateBonus(double salary){
        double bonus;

        if(programmingLanguage == "Java"){
            return bonus = 3/20 * salary;
        } else {
            return bonus = 1/10 * salary;
        }
    }
};