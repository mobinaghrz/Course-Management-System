#include <iostream>
#include <Person.h>
#include <vector>


class Student : public Person{

    protected:

        std::string major;
        double GPA;
        std::vector<std::string> EnrolledCourses;

    public:
        virtual void DisplayInfo();
        void EnrollInCourse(const std::string& course);

};