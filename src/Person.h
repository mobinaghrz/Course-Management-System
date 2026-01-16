// Responsible for: Base class for all people in the system
// Contains: Common attributes (id, name, email, age)

#include<string>

// If PERSON_H is not defined, define it (start of header guard)
#ifndef PERSON_H
// Define PERSON_H to prevent multiple inclusions
#define PERSON_H

class Person{

    protected:
        std::string name;
        int id;
        int age;
        std::string email;

    public:
        Person(const int& id, const std::string& name, std::string& email);

        virtual void DisplayInfo() const = 0;
        virtual void Save(std::ostream& out) const;

};

#endif