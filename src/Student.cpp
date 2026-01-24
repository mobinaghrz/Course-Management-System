#include "Student.h"

void Student::DisplayInfo(){
    std::cout << "Student ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Major: " << major << std::endl;
    std::cout << "GPA: " << GPA << std::endl;
    std::cout << "Enrolled Courses: ";
    for (const auto& course : EnrolledCourses) {
        std::cout << course << " ";
    }
    std::cout << std::endl;
}