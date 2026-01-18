#include <iostream>
#include <Person.h>
#include <vector>


class Student : public Person{

    protected:

        std::string major;
        double GPA;
        std::vector EnrolledCourses;

    public:
        virtual void DisplayInfo();
        EnrollInCourse();

};