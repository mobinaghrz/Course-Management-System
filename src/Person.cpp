#include <string>
#include <iostream>
#include "Person.h"

Person::Person(const int& id, const std::string& name,const std::string& email):id(id),name(name),email(email),age(0){};

void Person::Save(std::ostream& out) const{
    out << id << "\n";
    out << name << "\n";
    out << age << "\n";
    out << email << "\n";
}