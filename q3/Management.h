#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <iostream>
#include <algorithm>

class Employee {
private:
    std::string name;
    std::string position;
    double salary;

public:
    Employee();
    std::string getName();
    void setName(std::string n);
    std::string getPosition();
    void setPosition(std::string p);
    double getSalary();
    void setSalary(double s);
    virtual double calculateBonus() = 0;
};

class Manager : public Employee{
private: 
    int teamSize;

public:
    int getTeamSize();
    void setTeamSize(int t);
    double calculateBonus();
};

class Developer : public Employee{
private:
    std::string programmingLanguage;

public:
    std::string getProgrammingLanguage();
    void setProgrammingLanguage(std::string pl);
    double calculateBonus();
};

#endif /* MANAGEMENT_H */