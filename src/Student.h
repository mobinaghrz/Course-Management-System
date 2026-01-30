#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
#include <vector>
#include <unordered_map>

class Student : public Person {
private:
    std::string major;
    double gpa;
    std::vector<std::string> enrolledCourses;  // or vector<int> if course IDs are ints
    std::unordered_map<std::string, double> grades;  // courseId -> grade

public:
    // Constructors
    Student();
    Student(int id, const std::string& name, const std::string& email, 
            int age, const std::string& major);
    
    // Override from Person
    void DisplayInfo() const override;
    std::string getRole() const override { return "Student"; }
    void Save(std::ostream& out) const override;
    void Load(std::istream& in) override;
    
    // Student-specific methods
    void enrollInCourse(const std::string& courseId);
    void dropCourse(const std::string& courseId);
    void addGrade(const std::string& courseId, double grade);
    
    // Getters
    std::string getMajor() const { return major; }
    double getGPA() const { return gpa; }
    const std::vector<std::string>& getEnrolledCourses() const { 
        return enrolledCourses; 
    }
    
    // Operator overloading
    Student& operator+=(const std::string& courseId);  // Enroll
    
private:
    void calculateGPA();  // Helper function
};

#endif