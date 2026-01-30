#include "Student.h"
#include <iostream>

void Student::DisplayInfo() const {  // ← ADD const
    std::cout << "Student ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Major: " << major << std::endl;
    std::cout << "GPA: " << gpa << std::endl;  // ← lowercase
    std::cout << "Enrolled Courses: ";
    for (const auto& course : enrolledCourses) {  // ← lowercase
        std::cout << course << " ";
    }
    std::cout << std::endl;
}